#include "Queen.h"

Queen::Queen(PieceColour colour) : Piece(colour) {
}
Queen::~Queen() {}
QString Queen::getPieceType() {
    return QString("♛");
}
