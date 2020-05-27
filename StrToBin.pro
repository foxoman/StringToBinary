QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

#QMAKE_LFLAGS -= -O2
#QMAKE_LFLAGS += -static -s -Os -ffunction-sections -fdata-sections -Wl,--gc-sections
#QMAKE_LFLAGS += -Wl,-dynamic-linker=/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2

#QMAKE_LFLAGS += -static -s -Os

CONFIG(release, debug|release){
    DESTDIR = ./release/bin
    OBJECTS_DIR = release/.obj
    MOC_DIR = release/.moc
    RCC_DIR = release/.rcc
    UI_DIR = release/.ui
}

CONFIG(debug, debug|release){
    DESTDIR = ./debug/bin
    OBJECTS_DIR = debug/.obj
    MOC_DIR = debug/.moc
    RCC_DIR = debug/.rcc
    UI_DIR = debug/.ui
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#unix:QMAKE_CXX = ccache $$QMAKE_CXX

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
