#ifndef QUEENMOVE_H
#define QUEENMOVE_H
#include "moves/move.h"

class QueenMove : public Move
{
public:
    QueenMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);
};

#endif // QUEENMOVE_H
