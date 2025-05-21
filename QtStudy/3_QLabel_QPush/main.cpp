
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QLabel hello("<font color=blue>Hello <i>Qt!</i> </font>",&w);
    hello.resize(75,35);
    QPushButton quit("Quit",&w);
    quit.resize(75,35);
    quit.move(10,30);

    QObject ::connect(&quit,&QPushButton::clicked, &hello, [&](){hello.setText("<b>Hi</b>");});
    w.show();
    return a.exec(); // 무한 루프로 프로그램이 종료되는 것을 방지, 하드웨어 이벤트를 감지하면 해당 동작 처리를 진행

}
