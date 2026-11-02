#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QLabel;
class QTimer;
class QCloseEvent;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void newFile();
    void openFile();
    bool saveFile();
    bool saveFileAs();
    void updateActions();
    void findText();
    void replaceText();
    void showAbout();
    void goToLine();
    void chooseFont();
    void chooseTextColor();
    void chooseBackgroundColor();
    void autoSave();
private:
    bool maybeSave();
    bool loadFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fileName) const;
    Ui::MainWindow *ui;
    QLabel *positionLabel;
    QTimer *saveTimer;
    QString currentFile;
};
#endif
