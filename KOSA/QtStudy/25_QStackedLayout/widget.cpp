#include "widget.h"
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDial *dial = new QDial(this);
    dial->setRange(0,2);
    QLabel *label = new QLabel("stack 1",this);
    QCalendarWidget *calendarWidget = new QCalendarWidget(this);
    QTextEdit *textEdit = new QTextEdit("stack 3",this);

    // this를 쓰면 화면이 이상해짐
    // layout들을 지정할때는 this를 사용하지말자.
    QStackedLayout *stackedLayout = new QStackedLayout();

    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial, &QDial::valueChanged, stackedLayout, &QStackedLayout::setCurrentIndex);
    // connect(dial, SIGNAL(vlaueChanged(int)), stackedLayout, SLOT(setCurrentIndex(int)));

    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    setLayout(hBoxLayout);

}

Widget::~Widget() {}
