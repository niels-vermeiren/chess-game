#ifndef PAWNMOVE_H
#define PAWNMOVE_H
#include "moves/move.h"

class PawnMove : public Move {
    public:
        PawnMove(Piece * piece, QList<QList<Square *>> board);
        QList<QList<int>> getPossibleMoves();
};

#endif // PAWNMOVE_H
