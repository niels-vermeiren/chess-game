#include "Pawn.h"

Pawn::Pawn(PieceColour colour): Piece(colour) {
}
Pawn::~Pawn() {}
QString Pawn::getPieceType() const {
    return QString("♟");
}
QString Pawn::piece() const {
    return this->getPieceType();
};

void Pawn::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
