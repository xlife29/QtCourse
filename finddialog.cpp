#include "finddialog.h"
#include "ui_finddialog.h"
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextCursor>
#include <QTextDocument>
#include <QPushButton>

FindDialog::FindDialog(QPlainTextEdit *textEditor, QWidget *parent)
    : QDialog(parent), ui(new Ui::FindDialog), editor(textEditor)
{
    ui->setupUi(this);
    if (editor->textCursor().hasSelection()) ui->findEdit->setText(editor->textCursor().selectedText());
    connect(ui->findNextButton, &QPushButton::clicked, this, &FindDialog::findNext);
    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->findEdit, &QLineEdit::returnPressed, this, &FindDialog::findNext);
}
FindDialog::~FindDialog() { delete ui; }
void FindDialog::findNext()
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
