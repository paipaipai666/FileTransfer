QT += core gui widgets
QT += network

CONFIG += c++17

LIBS += -lws2_32

win32-msvc*:QMAKE_CXXFLAGS += /utf-8
# QMAKE_LFLAGS += "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""

SOURCES += \
    $$files($$PWD/src/*.cpp) \
    $$files($$PWD/utl/*.cpp)

HEADERS += \
    $$files($$PWD/src/*.h) \
    $$files($$PWD/utl/*.h)

FORMS += $$PWD/src/FileTransfer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target