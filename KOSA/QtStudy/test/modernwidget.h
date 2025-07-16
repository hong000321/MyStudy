#ifndef MODERNWIDGET_H
#define MODERNWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ModernWidget; }
QT_END_NAMESPACE

class ModernWidget : public QWidget
{
    Q_OBJECT

public:
    ModernWidget(QWidget *parent = nullptr);
    ~ModernWidget();

private slots:
    void onResetClicked();
    void onQuitClicked();
    void onLineEditChanged();
    void onDialValueChanged(int value);

private:
    Ui::ModernWidget *ui;
};

#endif // MODERNWIDGET_H
