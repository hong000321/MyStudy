#include "widget.h"
#include <QScrollArea>
#include <QScrollBar>
#include <QLabel>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QScrollArea* scrollArea = new QScrollArea(this);
    QLabel *label = new QLabel("1234567890123456789012345678901234567890",scrollArea);
    scrollArea->autoFillBackground();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(label);
    scrollArea->resize(200,100);
    scrollArea->show();
    QScrollBar *scrollbar = scrollArea->horizontalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
    // scrollbar->show();
}

Widget::~Widget() {}
