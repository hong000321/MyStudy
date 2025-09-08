#include "widget.h"
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <QPushButton>
#include <QMainWindow>
#include <QFont>
#include <QHash>
#include <QGridLayout>
#include <QVBoxLayout>

#include "Calculator.h"

#define MIN_WIDTH 600

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 결과 값 출력부 구현
    resultLabel = new QLabel(getResultString(),this);
    QFont resultFont = QFont("고딕체",40,3);
    resultLabel->setAlignment(Qt::AlignRight);
    resultLabel->setFont(resultFont);
    resultLabel->setMaximumSize(2000, 200);
    resultLabel->setMinimumSize(MIN_WIDTH, 100);


    fomulText = new QTextEdit(this);
    QFont fomulFont = QFont("고딕체",20,3);
    fomulText->setAlignment(Qt::AlignRight);
    fomulText->setFont(fomulFont);
    fomulText->setMaximumSize(2000, 200);
    fomulText->setMinimumSize(MIN_WIDTH, 100);
    fomulText->setReadOnly(true);
    // 키보드 버튼 구현
    buttonInit();

    // 레이아웃 구현
    QVBoxLayout *vLayout = new QVBoxLayout;
    resultLabel->setMaximumHeight(200);
    vLayout->addWidget(resultLabel);
    vLayout->addWidget(fomulText);
    QGridLayout *gridLayout = new QGridLayout;
    for(int y=0; y<NO_ROW; y++){
        for(int x=0; x<NO_COL; x++){
            gridLayout->addWidget(pushButton[x+y*NO_COL],y,x);
        }
    }
    vLayout->addLayout(gridLayout);
    setLayout(vLayout);

}

Widget::~Widget() {}

QString Widget::getResultString(){
    return QString("%1").arg(resultValue);
}

void Widget::buttonInit(){
    QFont buttonFont = QFont("고딕체",30,3);
    for(int i=0;i<NO_COL*NO_ROW; i++){
        pushButton[i] = new QPushButton(QChar(buttonCharList[i]),this);
        pushButton[i]->setMinimumHeight(MIN_WIDTH/(NO_ROW+1)-5);
        pushButton[i]->setMinimumWidth(MIN_WIDTH/(NO_COL+1)-5);

        pushButton[i]->setFont(buttonFont);
        connect(pushButton[i],&QPushButton::pressed,[=](){this->buttonAction(buttonCharList[i]);});
        if(buttonCharList[i] == 'n')
            pushButton[i]->setDisabled(true);
    }
}

void Widget::buttonAction(uchar ch){
    Calculator c;
    QChar qch(ch);

    if(qch.isDigit()||ch=='.'){
        qDebug() << "buttonAction() num : " << qch << Qt::endl;
        if(prevCalc=='='){
            currValue = 0;
            prevValue = 0;
            prevCalc = '+';
        }
        if(number==""&&ch=='0') // 0이 먼저 입력되는 상황
            return;
        if(number=="0")
            number="";
        number.append(qch);
        if(!(ch=='.'))
            currValue = number.toDouble();
        else
            currValue = number.toDouble();
        qDebug() << "number = " << number << Qt::endl;
    }else{
        qDebug() << "buttonAction() char : " << QChar(ch) << Qt::endl;
        resultLabel->clear();
        qreal tmpPrevVal = prevValue;
        qreal tmpCurrVal = currValue;
        QChar tmpQCalc = QChar(prevCalc);
        number.clear();
        switch (ch) {
        case '-':
        case '+':
        case '/':
        case 'x':
        case '%':
        case '^':
            qDebug() << "calc : " << prevValue << QChar(prevCalc) << currValue << Qt::endl;
            currValue = c.calc(prevValue, currValue, prevCalc);
            prevValue = currValue;
            prevCalc = ch;
            qDebug() << "result = " << prevValue << Qt::endl;
            break;
        case '=':
            currValue = c.calc(prevValue, currValue, prevCalc);
            prevCalc = ch;
            prevValue = currValue;
            break;
        case 'C':
            currValue = 0;
            prevValue = 0;
            prevCalc = '+';
            break;
        default:
            qDebug("buttonAction() : Unkown Input %c",ch);
            break;
        }
        QString tmpFomulText = QString("%1 %2 %3 = %4\n").arg(tmpPrevVal).arg(tmpQCalc).arg(tmpCurrVal).arg(currValue);
        QTextCursor cursor = fomulText->textCursor();
        cursor.movePosition(QTextCursor::Up);
        cursor.movePosition(QTextCursor::Start);
        cursor.insertText(tmpFomulText);
    }
    QString tmpNumStr=QString("%1").arg(currValue);
    if(ch=='.')
        tmpNumStr.append(qch);
    resultLabel->setText(tmpNumStr);
}




//=============================================================

