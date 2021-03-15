QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        board/BoardFactory.cpp \
        board/Square.cpp \
        board/board.cpp \
        board/chessviewmodel.cpp \
        main.cpp \
        pieces/Bishop.cpp \
        pieces/King.cpp \
        pieces/Knight.cpp \
        pieces/Pawn.cpp \
        pieces/Piece.cpp \
        pieces/Queen.cpp \
        pieces/Rook.cpp \
        twowaybindinglistsquare.cpp \
        twowaybindingsquare.cpp \
        twowaybindingtext.cpp

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
    board/BoardFactory.h \
    board/Square.h \
    board/board.h \
    board/chessviewmodel.h \
    pieces/Bishop.h \
    pieces/King.h \
    pieces/Knight.h \
    pieces/Pawn.h \
    pieces/Piece.h \
    pieces/Queen.h \
    pieces/Rook.h \
    twowaybindinglistsquare.h \
    twowaybindingsquare.h \
    twowaybindingtext.h
