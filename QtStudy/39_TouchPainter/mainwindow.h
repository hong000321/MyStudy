#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ScratchPad.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ScratchPad *m_scratchPad;

signals:
};

#endif // MAINWINDOW_H
