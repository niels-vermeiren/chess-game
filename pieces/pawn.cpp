#include "pawn.h"

Pawn::Pawn(PieceColour colour, int row, int col) : Piece(colour, row, col){}
Pawn::~Pawn() {}

Piece * Pawn::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    return new Pawn(colour, this->getRow(), this->getCol());
}

QString Pawn::pieceType() const {
    return QString("♟");
}

void Pawn::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
