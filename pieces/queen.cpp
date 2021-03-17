#include "queen.h"

Queen::Queen(PieceColour colour, int row, int col) : Piece(colour, row, col) {}

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
