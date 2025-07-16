#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    ui->setupUi(this);
    m_scratchPad = new ScratchPad(ui->tabWidget);
}
