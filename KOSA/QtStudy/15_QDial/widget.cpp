#include "widget.h"
#include <QDial>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDial *dial =new QDial(this);
    dial->setWrapping(true);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(10);
}

Widget::~Widget() {}
