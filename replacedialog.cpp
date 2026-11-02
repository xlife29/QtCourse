#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QTextDocument>

ReplaceDialog::ReplaceDialog(QPlainTextEdit *textEditor, QWidget *parent)
    : QDialog(parent), ui(new Ui::ReplaceDialog), editor(textEditor)
{
    ui->setupUi(this);
    if (editor->textCursor().hasSelection()) ui->findEdit->setText(editor->textCursor().selectedText());
    connect(ui->findNextButton, &QPushButton::clicked, this, &ReplaceDialog::findNext);
    connect(ui->replaceButton, &QPushButton::clicked, this, &ReplaceDialog::replaceCurrent);
    connect(ui->replaceAllButton, &QPushButton::clicked, this, &ReplaceDialog::replaceAll);
    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
}
ReplaceDialog::~ReplaceDialog() { delete ui; }

void ReplaceDialog::findNext()
{
    const QString needle = ui->findEdit->text();
    if (needle.isEmpty()) { QMessageBox::information(this, tr("查找"), tr("请输入要查找的内容。")); return; }
    QTextDocument::FindFlags flags;
    if (ui->caseSensitiveCheck->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    if (!editor->find(needle, flags)) {
        QTextCursor cursor = editor->textCursor(); cursor.movePosition(QTextCursor::Start); editor->setTextCursor(cursor);
        if (!editor->find(needle, flags)) QMessageBox::information(this, tr("查找"), tr("未找到“%1”。").arg(needle));
    }
}
void ReplaceDialog::replaceCurrent()
{
    const QString needle = ui->findEdit->text();
    if (needle.isEmpty()) { QMessageBox::information(this, tr("替换"), tr("请输入要查找的内容。")); return; }
    QTextCursor cursor = editor->textCursor();
    bool matches = cursor.hasSelection() && (ui->caseSensitiveCheck->isChecked()
        ? cursor.selectedText() == needle : cursor.selectedText().compare(needle, Qt::CaseInsensitive) == 0);
    if (matches) cursor.insertText(ui->replaceEdit->text());
    findNext();
}
void ReplaceDialog::replaceAll()
{
    const QString needle = ui->findEdit->text();
    if (needle.isEmpty()) { QMessageBox::information(this, tr("替换"), tr("请输入要查找的内容。")); return; }
    QTextDocument *document = editor->document();
    QTextCursor cursor(document); cursor.beginEditBlock(); int count = 0;
    QTextDocument::FindFlags flags;
    if (ui->caseSensitiveCheck->isChecked()) flags |= QTextDocument::FindCaseSensitively;
    while (!(cursor = document->find(needle, cursor, flags)).isNull()) {
        cursor.insertText(ui->replaceEdit->text()); ++count;
    }
    cursor.endEditBlock();
    QMessageBox::information(this, tr("全部替换"), count ? tr("已替换 %1 处。").arg(count) : tr("未找到“%1”。").arg(needle));
}
