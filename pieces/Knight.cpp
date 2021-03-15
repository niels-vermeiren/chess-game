#include "Knight.h"

Knight::Knight(PieceColour colour) : Piece(colour) {
}
Knight::~Knight() {}

QString Knight::getPieceType() {
    return QString("♞");
}
