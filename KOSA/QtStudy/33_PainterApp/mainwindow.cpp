#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(200,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event){
    qDebug("paintEvent");
    int mult = 0;
    int px = 20 + 160*mult;
    int px2 = px + 140*(mult+1);
    int py = 20 + 160*mult;
    int py2 = py + 140*(mult+1);
    QPainter paint(this);
    paint.setPen(QPen(Qt::blue, 5, Qt::DashLine));
    paint.drawPoint(100, 100);
    paint.setPen(QPen(Qt::green, 5, Qt::DotLine));
    paint.drawLine(px,py, px2, py2);
    paint.setPen(QPen(Qt::red, 5, Qt::SolidLine));
    paint.drawRect(px,py, px2, py2);
    paint.setPen(QPen(Qt::yellow, 5, Qt::DashDotLine));
    paint.drawRoundedRect(px,py, px2, py2,50,80);

    paint.setPen(QPen(Qt::red, 5, Qt::SolidLine));
    paint.drawText(120,100,"Text");
}
