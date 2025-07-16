QT += core widgets

CONFIG += c++17

TARGET = ModernWidget
TEMPLATE = app

# 소스 파일
SOURCES += \
    main.cpp \
    ModernWidget.cpp

# 헤더 파일
HEADERS += \
    ModernWidget.h

# UI 파일
FORMS += \
    ModernWidget.ui

# 빌드 디렉토리 설정
CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug/.obj
    MOC_DIR = debug/.moc
    UI_DIR = debug/.ui
} else {
    DESTDIR = release
    OBJECTS_DIR = release/.obj
    MOC_DIR = release/.moc
    UI_DIR = release/.ui
}

# 임베디드 시스템을 위한 추가 설정 (필요시)
# DEFINES += QT_NO_DEBUG_OUTPUT
# QMAKE_CXXFLAGS += -Os
