#include "knight.h"

Knight::Knight(PieceColour colour, int row, int col) : Piece(colour, row, col) {
}

Knight::~Knight() {}

QString Knight::pieceType() const {
    return QString("♞");
}

void Knight::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
