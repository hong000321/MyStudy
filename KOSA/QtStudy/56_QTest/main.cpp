#include <QCoreApplication>
#include <QtTest>
#include "dog.h"
#include "widget.h"


int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    // Dog dog;
    Widget widget;
    // QTest::qExec(&dog);
    QTest::qExec(&widget);

    return a.exec();
}
