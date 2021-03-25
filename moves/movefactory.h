#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include "moves/move.h"
#include "moves/pawnmove.h"
#include "moves/knightmove.h"
#include "moves/bishopmove.h"
#include "moves/rookmove.h"
#include "moves/queenmove.h"
#include "moves/kingmove.h"

class MoveFactory {
    public:
        static Move * createMoveStrategy(Piece * piece, QList<QList<Square *>> squares);
};

#endif // MOVEFACTORY_H
