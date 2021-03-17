#ifndef PAWNMOVE_H
#define PAWNMOVE_H
#include "moves/move.h"

class PawnMove : public Move
{
public:
    PawnMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);
};

#endif // PAWNMOVE_H
