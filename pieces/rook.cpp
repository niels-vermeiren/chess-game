#include "pieces/rook.h"

Rook::Rook(PieceColour colour) : Piece(colour) {}

Rook::~Rook() {}

QString Rook::pieceType() const {
    return QString("♜");
}

void Rook::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
