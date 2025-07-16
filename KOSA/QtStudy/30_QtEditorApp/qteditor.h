#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
class QAction;
class QTextEdit;
class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();
public slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void printFile();
    void quitFile();
    void alignText();
private:
    QTextEdit *textEdit;

    template<typename T>
    QAction *makeAction(QString icon, QString text, T shortCut, QString toolTip, QObject* rect, const char* slot);

    // template<>
    // QAction *makeAction(QString icon, QString text, const char* shortCut, QString toolTip, QObject* recv, const char* slot);

    template<typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut, QString toolTip, Functor lambda);
};
#endif // QTEDITOR_H
