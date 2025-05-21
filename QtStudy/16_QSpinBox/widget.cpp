#include "widget.h"
#include <QSpinBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->setRange(0,10);
    spinBox->setSuffix("%");
    spinBox->setWrapping(false);
    spinBox->resize(400,100);
    spinBox->setSpecialValueText("Percent"); // percent가 0(첫 값) 대신 들어감
}

Widget::~Widget() {}
