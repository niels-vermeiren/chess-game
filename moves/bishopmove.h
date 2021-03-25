#ifndef BISHOPMOVE_H
#define BISHOPMOVE_H

#include "moves/move.h"

class BishopMove : public Move {
    public:
        BishopMove(Piece * piece, QList<QList<Square *>> squares);
        QList<QList<int>> getPossibleMoves();
};

#endif // BISHOPMOVE_H
