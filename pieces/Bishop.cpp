#include "Bishop.h"

Bishop::Bishop(PieceColour colour) : Piece(colour) {

}
QString Bishop::getPieceType() {
    return QString("♝");
}
Bishop::~Bishop() {}
