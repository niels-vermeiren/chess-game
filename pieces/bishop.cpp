#include "bishop.h"

Bishop::Bishop(PieceColour colour) : Piece(colour) {

}
Bishop::~Bishop() {}

QString Bishop::pieceType() const {
    return QString("♝");
}

void Bishop::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
