#ifndef KINGMOVE_H
#define KINGMOVE_H
#include "moves/move.h"

class KingMove : public Move
{
public:
    KingMove();
    QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);

};

#endif // KINGMOVE_H
