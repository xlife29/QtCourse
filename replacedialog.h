#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H
#include <QDialog>
class QPlainTextEdit;
namespace Ui { class ReplaceDialog; }
class ReplaceDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ReplaceDialog(QPlainTextEdit *editor, QWidget *parent = nullptr);
    ~ReplaceDialog();
private slots:
    void findNext();
    void replaceCurrent();
    void replaceAll();
private:
    Ui::ReplaceDialog *ui;
    QPlainTextEdit *editor;
};
#endif
