#include "widget.h"
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setGeometry(0,0,500,100);

    QLCDNumber *lcd = new QLCDNumber(this);
    // lcd->setBinMode();
    lcd->setHexMode();
    // lcd->setOctMode();
    lcd->setSegmentStyle(QLCDNumber::Flat);

    lcd->display(22);
    lcd->setDigitCount(20);
    lcd->show();
}

Widget::~Widget() {}
