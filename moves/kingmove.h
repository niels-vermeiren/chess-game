#ifndef KINGMOVE_H
#define KINGMOVE_H
#include "moves/move.h"

class KingMove : public Move
{
public:
    KingMove(Piece * piece, QList<QList<Square *>> squares);
    QList<QList<int>> getPossibleMoves();

};

#endif // KINGMOVE_H
