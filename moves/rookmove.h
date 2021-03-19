#ifndef ROOKMOVE_H
#define ROOKMOVE_H

#include "moves/move.h"

class RookMove : public Move
{
public:
    RookMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);
};

#endif // ROOKMOVE_H
