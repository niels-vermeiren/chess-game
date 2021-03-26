#include "king.h"

King::King(PieceColour colour, int row, int col) : Piece(colour, row, col) {}
King::~King() {}

Piece * King::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    Piece * king = new King(colour, this->getRow(), this->getCol());
    king->setMoved(this->hasMoved());
    return king;
}

QString King::pieceType() const {
    return QString("♚");
}

void King::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}

int King::getScore() {
    return 900;
}
