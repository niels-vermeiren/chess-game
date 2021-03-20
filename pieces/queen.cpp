#include "queen.h"

Queen::Queen(PieceColour colour, int row, int col) : Piece(colour, row, col) {}

Queen::~Queen() {}

Piece * Queen::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    return new Queen(colour, this->getRow(), this->getCol());
}

QString Queen::pieceType() const {
    return QString("♛");
}

void Queen::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
