#include <QApplication>
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[]) // 명령형 인수(command line)
{
    QApplication a(argc, argv);
    QLabel hello("<font size=4 color=blue>"
                 "Hello </font>"
                 "<font size=8 color=red><i>Qt!</i></font>",nullptr);
    hello.resize(100,55); // resize하지 않으면 텍스트 최소 영역만 설정하기 때문에 플랫폼에 따라 달라짐.
    hello.show();
    return a.exec(); // 무한 루프로 프로그램이 종료되는 것을 방지, 하드웨어 이벤트를 감지하면 해당 동작 처리를 진행
}
