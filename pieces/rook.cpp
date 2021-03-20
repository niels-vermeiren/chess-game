#include "pieces/rook.h"

Rook::Rook(PieceColour colour, int row, int col) : Piece(colour, row, col) {}

Piece * Rook::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    return new Rook(colour, this->getRow(), this->getCol());
}

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
