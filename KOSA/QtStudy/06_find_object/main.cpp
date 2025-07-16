#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    // QObject::connect(&w,SIGNAL(clicked()),&a,SLOT(quit()));
    w.show();
    return a.exec();
}
