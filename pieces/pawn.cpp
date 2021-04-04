#include "pawn.h"

Pawn::Pawn(PieceColour colour, int row, int col) : Piece(colour, row, col){}
Pawn::~Pawn() {}

Piece * Pawn::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    Piece * pawn = new Pawn(colour, this->getRow(), this->getCol());
    pawn->setMoved(this->hasMoved());
    return pawn;
}

QString Pawn::pieceType() const {
    return QString("♟");
}

void Pawn::setPiece(QString piece) {
    if (this->m_piece == piece) return;
    this->m_piece = piece;
    emit pieceChanged();
}

int Pawn::getScore() {
    return 10;
}
