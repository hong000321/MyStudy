#include "qteditor.h"
#include <QLabel>
#include <QTextEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QString>
#include <QStatusBar>
#include <QApplication>
#include <QFontComboBox>
#include <QDoubleSpinBox>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // MenuBar, Menu 설정
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");
    QMenu *editMenu = menuBar->addMenu("&Edit");
    QMenu *formatMenu = menuBar->addMenu("&Format");
    QMenu *windowMenu = menuBar->addMenu("&Window");

    QMenu *toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction("test");

    // 상태바 추가
    QStatusBar *statusBar = this->statusBar();
    QLabel *statusLabel = new QLabel(tr("Qt Editor"), statusBar);
    statusLabel->setObjectName("StatusLabel");
    statusBar->addPermanentWidget(statusLabel);
    statusBar->showMessage("started",1500); // 뒷 숫자는 ms단위의 시간

    // 텍스트 에디터 메인 위젯으로 설정
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit); // 메인 위젯으로 설정되어 크기가 창에 맞춰짐

// =================== Actions ===================
    // File 메뉴 Actions 1 : SLOT 형식 구현
    QAction *newAct = makeAction("./icons/new.png","&New","Ctrl+N","make new file",this,SLOT(newFile()));
    QAction *openAct = makeAction("./icons/open.png","&Open",QKeySequence::Open,"Open file",this,SLOT(openFile()));
    QAction *saveAct = makeAction("./icons/save.png","&Save","Ctrl+S","Save file",this,SLOT(saveFile()));
    QAction *saveAsAct = makeAction("./icons/saveas.png","&Save as",QKeySequence::SaveAs,"Save as file",this,SLOT(saveAsFile()));
    QAction *printAct = makeAction("./icons/print.png","&Print","Ctrl+P","Print file",this,SLOT(printFile()));
    QAction *quitAct = makeAction("./icons/quit.png","&Quit","Ctrl+q","Quit file",this,SLOT(quitFile()));

    // File 메뉴 Actions 2 : lambda 형식 구현
    // QAction *newAct = makeAction("ne2w.png","&New","Ctrl+N","make new file",[&](){newFile();});
    // QAction *openAct = makeAction("open.png","&Open",QKeySequence::Open,"Open file",[&](){openFile();});
    // QAction *saveAct = makeAction("save.png","&Save","Ctrl+S","Save file",[&](){saveFile();});
    // QAction *saveAsAct = makeAction("saveas.png","&Save as","Ctrl+Shift+S","Save as file",[&](){saveAsFile();});
    // QAction *printAct = makeAction("print.png","&Print","Ctrl+P","Print file",[&](){printFile();});
    // QAction *quitAct = makeAction("quit.png","&Quit","Ctrl+q","Quit file",[&](){quitFile();});

    // Edit 메뉴 Action
    QAction *undoAct = makeAction("./icons/undo.png","&Undo",QKeySequence::Undo,"Undo",textEdit,SLOT(undo()));
    QAction *redoAct = makeAction("./icons/redo.png","&Redo",QKeySequence::Redo,"Redo",textEdit,SLOT(redo()));
    QAction *copyAct = makeAction("./icons/copy.png","&Copy",QKeySequence::Copy,"Copy",textEdit,SLOT(copy()));
    QAction *cutAct = makeAction("./icons/cut.png","&Cut",QKeySequence::Cut,"Cut",textEdit,SLOT(cut()));
    QAction *pasteAct = makeAction("./icons/paste.png","&Paste",QKeySequence::Paste,"Paste",textEdit,SLOT(paste()));
    QAction *zoomInAct = makeAction("./icons/zoomin.png","&Zoom in",QKeySequence::ZoomIn,"Zoom in",textEdit,SLOT(zoomIn()));
    QAction *zoomOutAct = makeAction("./icons/zoomout.png","&Zoom out",QKeySequence::ZoomOut,"Zoom out",textEdit,SLOT(zoomOut()));

    // Format 메뉴 Action

    // QAction *fontAct = makeAction("./icons/font.png","&font",NULL,"font",textEdit,SLOT(setCurrentFont())); 수정 필요
    // QAction *colorAct = makeAction("./icons/color.png","&color",NULL,"color",textEdit,SLOT(setTextColor()));
    QAction *alignCenterAct = makeAction("./icons/alignCenter.png","&alignCenter",NULL,"alignCenter",this,SLOT(alignText()));
    QAction *alignLeftAct = makeAction("./icons/alignLeft.png","&alignLeft",NULL,"alignLeft",this,SLOT(alignText()));
    QAction *alignRightAct = makeAction("./icons/alignRight.png","&alignRight",NULL,"alignRight",this,SLOT(alignText()));
    QAction *alignJustifyAct = makeAction("./icons/justify.png","&alignJustify",NULL,"alignJustify",this,SLOT(alignText()));
    // QAction *alignCenterAct = makeAction("./icons/alignCenter.png","&alignCenter",NULL,"alignCenter",textEdit,SLOT(setAlignment()));
    // QAction *alignLeftAct = makeAction("./icons/alignLeft.png","&alignLeft",NULL,"alignLeft",[=](){textEdit->setAlignment(Qt::AlignLeft);});


// ================ Actions Mapping
    // file Action 맵핑
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(printAct);
    fileMenu->addAction(quitAct);

    // edit Action 맵핑
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    // format Action 맵핑
    // formatMenu->addAction(fontAct);
    // formatMenu->addAction(colorAct);
    formatMenu->addAction(alignCenterAct);
    formatMenu->addAction(alignLeftAct);
    formatMenu->addAction(alignRightAct);
    formatMenu->addAction(alignJustifyAct);

// =================== ToolBar ===================
    // file ToolBar 설정
    QToolBar *fileToolBar = addToolBar("&File");
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    // file Tool Action 맵핑
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveAsAct);
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    // 툴바 줄 변경
    addToolBarBreak();

    // 툴바에 글꼴 추가
    QFontComboBox *fontComboBox = new QFontComboBox(this);
    connect(fontComboBox,SIGNAL(currentFontChanged(QFont)),textEdit,SLOT(setCurrentFont(QFont)));
    QToolBar *formatToolbar = addToolBar("&Format");


    // 툴바에 글꼴 추가
    QDoubleSpinBox *sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox,SIGNAL(valueChanged(double)),textEdit,SLOT(setFontPointSize(qreal)));
    formatToolbar->addSeparator();

    // 포맷 툴바 맵핑
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);
}

void QtEditor::newFile(){
    qDebug("Make New File");
}

void QtEditor::openFile(){
    qDebug("Open File");
}

void QtEditor::saveFile(){
    qDebug("Save File");
}

void QtEditor::saveAsFile(){
    qDebug("Save as File");
}

void QtEditor::printFile(){
    qDebug("Print File");
}

void QtEditor::quitFile(){
    qDebug("Quit File");
    qApp->quit();
}

void QtEditor::alignText(){
    QAction *action = dynamic_cast<QAction*>(sender());
    if(action->text().contains("Left",Qt::CaseInsensitive))
        textEdit->setAlignment(Qt::AlignLeft);
    else if(action->text().contains("Right",Qt::CaseInsensitive))
        textEdit->setAlignment(Qt::AlignRight);
    else if(action->text().contains("Center",Qt::CaseInsensitive))
        textEdit->setAlignment(Qt::AlignCenter);
    else if(action->text().contains("Justify",Qt::CaseInsensitive))
        textEdit->setAlignment(Qt::AlignJustify);
}

template<typename T>
QAction *QtEditor::makeAction(QString icon, QString text, T shortCut, QString toolTip, QObject* recv, const char* slot){
    qDebug("Slot Fucntion!!!");
    QAction *act = new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    QKeySequence keySequence(shortCut);
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, SIGNAL(triggered()),recv,slot);
    return act;
}

// template<>
// QAction *QtEditor::makeAction(QString icon, QString text, const char* shortCut, QString toolTip, QObject* recv, const char* slot){
//     qDebug("Special Fucntion!!!");
//     QAction *act = new QAction(text,this);
//     if(icon.length())
//         act->setIcon(QIcon(icon));
//     QKeySequence keySequence(tr(shortCut));
//     act->setShortcut(keySequence);
//     act->setStatusTip(toolTip);
//     act->setToolTip(toolTip);
//     connect(act, SIGNAL(triggered()),recv,slot);
//     return act;
// }

template<typename T, typename Functor>
QAction *QtEditor::makeAction(QString icon, QString text, T shortCut, QString toolTip, Functor lambda){
    qDebug("lambda Fucntion!!!");
    QAction *act = new QAction(text,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    QKeySequence keySequence(shortCut); // shortCut을 const char*이든 QString이든 모두 내부적으로 QString으로 동작함.
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, &QAction::triggered,lambda);
    return act;
}

QtEditor::~QtEditor() {}
