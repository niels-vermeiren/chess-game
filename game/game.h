#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
#include "board/square.h"
#include "moves/movefactory.h"

class Game
{

public:
    Game();
    static QList<QList<int>> getPossibleMoves(QList<QList<Square *>> board, int row, int col);
    static bool isCheckForColour(QList<QList<Square *>> board, QString colour);
    static bool isCheckMateForColour(QList<QList<Square *>> board, QString colour);
    static bool isStaleMateForColour(QList<QList<Square *>> board, QString colour);
private:
    static Piece * castle(QList<QList<Square*>> board, Piece * piece, QList<int> possibleMove);
    static void reverseCastle(QList<QList<Square*>> board, Piece * piece);
    static bool isCastlingMove(Piece * piece, QList<int> possibleMove);
    static bool isLeftCastlingMove(Piece * piece, QList<int> possibleMove);
    static bool isRightCastlingMove(Piece * piece, QList<int> possibleMove);
signals:

};

#endif // GAME_H
