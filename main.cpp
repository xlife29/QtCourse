#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("SimpleTextEditor_Designer");
    MainWindow window;
    window.show();
    return app.exec();
}
