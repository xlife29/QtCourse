#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog>
class QPlainTextEdit;
namespace Ui { class FindDialog; }
class FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QPlainTextEdit *editor, QWidget *parent = nullptr);
    ~FindDialog();
private slots:
    void findNext();
private:
    Ui::FindDialog *ui;
    QPlainTextEdit *editor;
};
#endif
