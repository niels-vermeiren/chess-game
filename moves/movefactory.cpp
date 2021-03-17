#include "movefactory.h"

Move * MoveFactory::createMoveStrategy(Piece * piece) {
    if (piece->pieceType() == "♟") return new PawnMove();
    return new Move();
}
