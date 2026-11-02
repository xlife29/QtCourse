#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "codeeditor.h"
#include "replacedialog.h"
#include "finddialog.h"
#include "aboutdialog.h"
#include <QApplication>
#include <QClipboard>
#include <QCloseEvent>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDialog>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPalette>
#include <QStatusBar>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextStream>
#include <QTimer>
#include <QToolBar>
#include <QtGlobal>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QStringConverter>
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), positionLabel(new QLabel(this)), saveTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowTitle(tr("未命名 - 简单文本编辑器"));
    ui->statusbar->addPermanentWidget(positionLabel);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, [this]() { saveFile(); });
    connect(ui->actionSaveAs, &QAction::triggered, this, [this]() { saveFileAs(); });
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionUndo, &QAction::triggered, ui->editor, &QPlainTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->editor, &QPlainTextEdit::redo);
    connect(ui->actionCut, &QAction::triggered, ui->editor, &QPlainTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->editor, &QPlainTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->editor, &QPlainTextEdit::paste);
    connect(ui->actionSelectAll, &QAction::triggered, ui->editor, &QPlainTextEdit::selectAll);
    connect(ui->actionFind, &QAction::triggered, this, &MainWindow::findText);
    connect(ui->actionReplace, &QAction::triggered, this, &MainWindow::replaceText);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
    connect(ui->actionShowToolBar, &QAction::toggled, ui->toolBar, &QToolBar::setVisible);
    connect(ui->actionShowStatusBar, &QAction::toggled, ui->statusbar, &QStatusBar::setVisible);
    connect(ui->actionGoToLine, &QAction::triggered, this, &MainWindow::goToLine);
    connect(ui->actionFont, &QAction::triggered, this, &MainWindow::chooseFont);
    connect(ui->actionTextColor, &QAction::triggered, this, &MainWindow::chooseTextColor);
    connect(ui->actionBackgroundColor, &QAction::triggered, this, &MainWindow::chooseBackgroundColor);
    connect(ui->actionLineNumbers, &QAction::toggled, ui->editor, &CodeEditor::setLineNumbersVisible);
    connect(ui->actionWordWrap, &QAction::toggled, this, [this](bool enabled) { ui->editor->setLineWrapMode(enabled ? QPlainTextEdit::WidgetWidth : QPlainTextEdit::NoWrap); });
    connect(ui->editor->document(), &QTextDocument::modificationChanged, this, [this](bool) { updateActions(); });
    connect(ui->editor, &QPlainTextEdit::textChanged, this, &MainWindow::updateActions);
    connect(ui->editor, &QPlainTextEdit::copyAvailable, this, [this](bool) { updateActions(); });
    connect(QApplication::clipboard(), &QClipboard::dataChanged, this, &MainWindow::updateActions);
    connect(ui->editor, &QPlainTextEdit::cursorPositionChanged, this, [this]() {
        QTextCursor cursor = ui->editor->textCursor();
        positionLabel->setText(tr("第 %1 行，第 %2 列").arg(cursor.blockNumber() + 1).arg(cursor.positionInBlock() + 1));
    });
    connect(saveTimer, &QTimer::timeout, this, &MainWindow::autoSave);
    saveTimer->start(60000);
    updateActions();
}
MainWindow::~MainWindow() { delete ui; }
QString MainWindow::strippedName(const QString &name) const { return QFileInfo(name).fileName(); }
void MainWindow::newFile() { if (!maybeSave()) return; ui->editor->clear(); setCurrentFile(QString()); }
void MainWindow::openFile()
{
    if (!maybeSave()) return;
    QString name = QFileDialog::getOpenFileName(this, tr("打开文件"), QString(), tr("文本文件 (*.txt);;所有文件 (*)"));
    if (!name.isEmpty()) loadFile(name);
}
bool MainWindow::saveFile() { return currentFile.isEmpty() ? saveFileAs() : writeFile(currentFile); }
bool MainWindow::saveFileAs()
{
    QString name = QFileDialog::getSaveFileName(this, tr("另存为"), currentFile, tr("文本文件 (*.txt);;所有文件 (*)"));
    return name.isEmpty() ? false : writeFile(name);
}
bool MainWindow::maybeSave()
{
    if (!ui->editor->document()->isModified()) return true;
    QMessageBox box(QMessageBox::Warning, tr("文档已修改"), tr("文件“%1”已修改，是否保存？").arg(currentFile.isEmpty() ? tr("未命名") : strippedName(currentFile)), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, this);
    box.setDefaultButton(QMessageBox::Save);
    int result = box.exec();
    if (result == QMessageBox::Save) return saveFile();
    return result == QMessageBox::Discard;
}
bool MainWindow::loadFile(const QString &name)
{
    QFile file(name);
    if (!file.open(QFile::ReadOnly | QFile::Text)) { QMessageBox::warning(this, tr("打开失败"), tr("无法打开文件：%1\n%2").arg(name, file.errorString())); return false; }
    QTextStream stream(&file);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    stream.setEncoding(QStringConverter::Utf8);
#else
    stream.setCodec("UTF-8");
#endif
    ui->editor->setPlainText(stream.readAll());
    setCurrentFile(name);
    return true;
}
bool MainWindow::writeFile(const QString &name)
{
    QFile file(name);
    if (!file.open(QFile::WriteOnly | QFile::Text)) { QMessageBox::warning(this, tr("保存失败"), tr("无法保存文件：%1\n%2").arg(name, file.errorString())); return false; }
    QTextStream stream(&file);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    stream.setEncoding(QStringConverter::Utf8);
#else
    stream.setCodec("UTF-8");
#endif
    stream << ui->editor->toPlainText();
    file.close();
    setCurrentFile(name);
    return true;
}
void MainWindow::setCurrentFile(const QString &name)
{
    currentFile = name;
    ui->editor->document()->setModified(false);
    updateActions();
}
void MainWindow::updateActions()
{
    bool selected = ui->editor->textCursor().hasSelection();
    ui->actionCut->setEnabled(selected); ui->actionCopy->setEnabled(selected);
    ui->actionPaste->setEnabled(ui->editor->canPaste());
    ui->actionUndo->setEnabled(ui->editor->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(ui->editor->document()->isRedoAvailable());
    ui->actionSave->setEnabled(ui->editor->document()->isModified() || currentFile.isEmpty());
    QString name = currentFile.isEmpty() ? tr("未命名") : strippedName(currentFile);
    setWindowTitle(QString("%1%2 - 简单文本编辑器").arg(name, ui->editor->document()->isModified() ? "*" : ""));
}
void MainWindow::findText()
{
    FindDialog dialog(ui->editor, this);
    dialog.exec();
}
void MainWindow::replaceText()
{
    ReplaceDialog dialog(ui->editor, this);
    dialog.exec();
}
void MainWindow::showAbout()
{
    AboutDialog dialog(this);
    dialog.exec();
}
void MainWindow::goToLine()
{
    bool ok = false; int line = QInputDialog::getInt(this, tr("转到行"), tr("行号："), 1, 1, ui->editor->blockCount(), 1, &ok); if (!ok) return;
    QTextCursor cursor(ui->editor->document()->findBlockByNumber(line - 1)); ui->editor->setTextCursor(cursor); ui->editor->centerCursor();
}
void MainWindow::chooseFont() { bool ok; QFont font = QFontDialog::getFont(&ok, ui->editor->font(), this, tr("选择字体")); if (ok) ui->editor->setFont(font); }
void MainWindow::chooseTextColor() { QColor color = QColorDialog::getColor(ui->editor->palette().color(QPalette::Text), this, tr("选择文字颜色")); if (color.isValid()) { QPalette palette = ui->editor->palette(); palette.setColor(QPalette::Text, color); ui->editor->setPalette(palette); } }
void MainWindow::chooseBackgroundColor() { QColor color = QColorDialog::getColor(ui->editor->palette().color(QPalette::Base), this, tr("选择背景颜色")); if (color.isValid()) { QPalette palette = ui->editor->palette(); palette.setColor(QPalette::Base, color); ui->editor->setPalette(palette); } }
void MainWindow::autoSave() { if (ui->editor->document()->isModified() && !currentFile.isEmpty()) writeFile(currentFile); }
void MainWindow::closeEvent(QCloseEvent *event) { if (maybeSave()) event->accept(); else event->ignore(); }
