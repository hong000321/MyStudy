#include "widget.h"
#include <QComboBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("KDE");
    comboBox->addItem("Gnome");
    comboBox->addItem("FVWM");
    comboBox->addItem("CDE");
    comboBox->setEditable(true);

}

Widget::~Widget() {}
