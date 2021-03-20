#ifndef KNIGHTMOVE_H
#define KNIGHTMOVE_H

#include "moves/move.h"

class KnightMove : public Move
{
public:
    KnightMove(Piece * piece, QList<QList<Square *>> board);
    QList<QList<int>> getPossibleMoves();
};

#endif // KNIGHTMOVE_H
