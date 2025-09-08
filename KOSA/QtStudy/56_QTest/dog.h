#ifndef DOG_H
#define DOG_H

#include <QObject>
#include <QDebug>
#include <QTest>

class Dog : public QObject
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();
    void test_case1();

    void bark();
    void rollover();

    void simple();

signals:

};

#endif // DOG_H
