#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(54321);
    w.start();
    w.show();
    return a.exec();
}
