#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include "moves/move.h"
#include "moves/pawnmove.h"
#include "moves/knightmove.h"
#include "moves/bishopmove.h"

class MoveFactory
{
public:
    static Move * createMoveStrategy(Piece * piece);
};

#endif // MOVEFACTORY_H
