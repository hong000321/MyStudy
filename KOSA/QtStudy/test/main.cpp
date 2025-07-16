#include "modernwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModernWidget w;
    w.show();
    return a.exec();
}
