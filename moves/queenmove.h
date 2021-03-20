#ifndef QUEENMOVE_H
#define QUEENMOVE_H
#include "moves/move.h"

class QueenMove : public Move
{
public:
    QueenMove(Piece * piece, QList<QList<Square *>> squares);
    QList<QList<int>> getPossibleMoves();
};

#endif // QUEENMOVE_H
