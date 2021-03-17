#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include "moves/move.h"
#include "moves/pawnmove.h"

class MoveFactory
{
public:
    static Move * createMoveStrategy(Piece * piece);
};

#endif // MOVEFACTORY_H
