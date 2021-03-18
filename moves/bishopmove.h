#ifndef BISHOPMOVE_H
#define BISHOPMOVE_H

#include "moves/move.h"

class BishopMove : public Move
{
public:
    BishopMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);

private:
    QList<QList<int>> getMoves(bool isWhitePiece, int row, int col, int directionRow, int directionCol, QList<QList<Square *>> board);
};

#endif // BISHOPMOVE_H
