#include "widget.h"
#include <QSlider>
#include <QStyleFactory>
#include <QProgressBar>
#include <QObject>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QSlider *slider = new QSlider(this);
    slider->setGeometry(10,10,300,20);
    slider->setOrientation(Qt::Horizontal);
    slider->setTickInterval(QSlider::TicksAbove);
    slider->setStyle(QStyleFactory::create("Fusion"));


    QProgressBar *prog = new QProgressBar(this);
    prog->setGeometry(10,200,300,20);
    QObject::connect(slider,SIGNAL(valueChanged(int)),prog,SLOT(setValue(int)));
    // QObject::connect(slider,&QSlider::valueChanged,prog,&QProgressBar::setValue);

}

Widget::~Widget() {}
