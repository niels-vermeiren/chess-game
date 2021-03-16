#include "queen.h"

Queen::Queen(PieceColour colour) : Piece(colour) {}

Queen::~Queen() {}

QString Queen::pieceType() const {
    return QString("♛");
}

void Queen::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
