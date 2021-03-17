#include "pawn.h"

Pawn::Pawn(PieceColour colour, int row, int col) : Piece(colour, row, col){}
Pawn::~Pawn() {}

QString Pawn::pieceType() const {
    return QString("♟");
}

void Pawn::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
