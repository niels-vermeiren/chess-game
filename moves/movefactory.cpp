#include "movefactory.h"

Move * MoveFactory::createMoveStrategy(Piece * piece, QList<QList<Square *>> squares) {
    if (piece->pieceType() == "♟") return new PawnMove(piece, squares);
    if (piece->pieceType() == "♞") return new KnightMove(piece, squares);
    if (piece->pieceType() == "♝") return new BishopMove(piece, squares);
    if (piece->pieceType() == "♜") return new RookMove(piece, squares);
    if (piece->pieceType() == "♛") return new QueenMove(piece, squares);
    if (piece->pieceType() == "♚") return new KingMove(piece, squares);
    return new Move(piece, squares);
}
