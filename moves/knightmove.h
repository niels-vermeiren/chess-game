#ifndef KNIGHTMOVE_H
#define KNIGHTMOVE_H

#include "moves/move.h"

class KnightMove : public Move
{
public:
    KnightMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);
};

#endif // KNIGHTMOVE_H