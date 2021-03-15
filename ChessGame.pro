QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        board/boardfactory.cpp \
        board/boardviewmodel.cpp \
        board/square.cpp \
        main.cpp \
        pieces/bishop.cpp \
        pieces/king.cpp \
        pieces/knight.cpp \
        pieces/pawn.cpp \
        pieces/piece.cpp \
        pieces/queen.cpp \
        pieces/rook.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    board/boardfactory.h \
    board/boardviewmodel.h \
    board/square.h \
    pieces/bishop.h \
    pieces/king.h \
    pieces/knight.h \
    pieces/pawn.h \
    pieces/piece.h \
    pieces/queen.h \
    pieces/rook.h
