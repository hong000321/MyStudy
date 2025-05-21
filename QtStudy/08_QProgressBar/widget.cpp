#include "widget.h"
#include <QProgressBar>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QProgressBar *progBar = new QProgressBar(this);
    progBar->initStyleOption(QStyleOptionProgressBar::initStyleOption);
    progBar->setValue(20);
    progBar->setGeometry(10,10,300,50);
    // progBar->setInvertedAppearance(true);
    progBar->show();
}

Widget::~Widget() {}
