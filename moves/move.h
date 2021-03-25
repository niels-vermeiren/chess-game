#ifndef MOVE_H
#define MOVE_H

#include <QObject>
#include "board/square.h"

class Move : public QObject {
    Q_OBJECT

    public:
        Move(Piece * piece, QList<QList<Square *>> squares);
        Q_INVOKABLE virtual QList<QList<int>> getPossibleMoves();
        ~Move();
    protected:
        Piece * piece;
        QList<QList<Square *>> squares;
        QList<QList<int>> getAllMovesInDirection(int row, int col, int directionRow, int directionCol);
        QList<QList<int>> getOneMoveInDirection(int row, int col, int directionRow, int directionCol);
        QString getPieceType(int row, int col);
        QString getPieceColour(int row, int col);
};

#endif // MOVE_H
