// #include "mainwindow.h"
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget wg;
    wg.show();
    // MainWindow w;
    // w.show();
    return a.exec();
}
