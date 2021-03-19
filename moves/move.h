#ifndef MOVE_H
#define MOVE_H

#include <QObject>
#include "board/square.h"

class Move : public QObject
{
    Q_OBJECT
public:
    Move();
    Q_INVOKABLE virtual QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);

protected:
    QList<QList<int>> getAllMovesInDirection(bool isWhitePiece, int row, int col, int directionRow, int directionCol, QList<QList<Square *>> board);
    QString getPieceType(QList<QList<Square *>> board, int row, int col);
    QString getPieceColour(QList<QList<Square *>> board, int row, int col);
};

#endif // MOVE_H
