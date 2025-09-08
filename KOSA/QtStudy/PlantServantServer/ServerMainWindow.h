#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ServerMainWindow;
}
QT_END_NAMESPACE

class ServerMainWindow : public QWidget
{
    Q_OBJECT

public:
    ServerMainWindow(QWidget *parent = nullptr);
    ~ServerMainWindow();

private:
    Ui::ServerMainWindow *ui;
};
#endif // SERVERMAINWINDOW_H
