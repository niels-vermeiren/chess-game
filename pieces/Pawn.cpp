#include "Pawn.h"

Pawn::Pawn(PieceColour colour): Piece(colour) {
}
Pawn::~Pawn() {}
QString Pawn::getPieceType() {
    return QString("♟");
}
