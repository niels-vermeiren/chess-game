#ifndef ROOKMOVE_H
#define ROOKMOVE_H

#include "moves/move.h"

class RookMove : public Move {
    public:
        RookMove(Piece * piece, QList<QList<Square *>> squares);
        QList<QList<int>> getPossibleMoves();
};

#endif // ROOKMOVE_H
