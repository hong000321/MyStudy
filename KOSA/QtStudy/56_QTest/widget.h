#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QTest>

class Widget : public QObject
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);
    void setAge(int value);

private slots:
    void testFail();
    void testAge();
    void testWidget();
private:
    int age;
signals:
};

#endif // WIDGET_H
