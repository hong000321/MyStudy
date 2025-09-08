#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
// class QHash;
class QAction;
class QPushButton;
class QLabel;
class QTextEdit;
#define NO_COL 4
#define NO_ROW 5
class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:



private:
    QString getResultString();
    void buttonInit();
    void buttonAction(uchar ch);

    QPushButton *pushButton[NO_COL*NO_ROW];
    // uchar buttonCharList[NO_COL*NO_ROW]={'7','8','9','/',
    //                                          '4','5','6','x',
    //                                          '1','2','3','-',
    //                                          '0','C','=','+'};
    uchar buttonCharList[NO_COL*NO_ROW]={
                                             '^','%','C','x',
                                             '7','8','9','/',
                                             '4','5','6','+',
                                             '1','2','3','-',
                                             '.','0','n','='};

    QString number="";
    QLabel *resultLabel;
    QTextEdit *fomulText;
    uchar prevCalc='+';
    qreal prevValue=0;
    qreal currValue=0;
    qreal resultValue=0;

};
#endif // WIDGET_H
