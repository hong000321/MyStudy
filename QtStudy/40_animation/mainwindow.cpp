#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,40,20);
    rect->setBrush(QBrush(Qt::blue));

    QTimeLine *timeLine = new QTimeLine(5000);
    timeLine->setFrameRange(0,100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(rect);
    animation->setTimeLine(timeLine);

    for(int i=0; i<200; i++)
        animation->setPosAt(i/200.0, QPointF(i, i));

    animation->setRotationAt(80.0/200.0,30);
    animation->setRotationAt(180.0/200.0,90);

    QGraphicsScene *scene= new QGraphicsScene();
    scene->setSceneRect(0,0,250,250);
    scene->addItem(rect);

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();
    timeLine->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
