#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]) // 명령형 인수(command line)
{
    QApplication a(argc, argv);
    QPushButton quit("Quit",nullptr);
    quit.resize(75,35);
    quit.move(10,30);
    quit.show();
    QObject ::connect(&quit,"2clicked()", &a, "1quit()"); // SLOT(), SIGNAL() 은 (메타데이터+입력)을 문자열 처리
    return a.exec(); // 무한 루프로 프로그램이 종료되는 것을 방지, 하드웨어 이벤트를 감지하면 해당 동작 처리를 진행
}
