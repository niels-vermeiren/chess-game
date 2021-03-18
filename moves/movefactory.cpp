#include "movefactory.h"

Move * MoveFactory::createMoveStrategy(Piece * piece) {
    if (piece->pieceType() == "♟") return new PawnMove();
    if (piece->pieceType() == "♞") return new KnightMove();
    return new Move();
}
