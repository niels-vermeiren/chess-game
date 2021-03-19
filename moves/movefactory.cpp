#include "movefactory.h"

Move * MoveFactory::createMoveStrategy(Piece * piece) {
    if (piece->pieceType() == "♟") return new PawnMove();
    if (piece->pieceType() == "♞") return new KnightMove();
    if (piece->pieceType() == "♝") return new BishopMove();
    if (piece->pieceType() == "♜") return new RookMove();
    if (piece->pieceType() == "♛") return new QueenMove();
    return new Move();
}
