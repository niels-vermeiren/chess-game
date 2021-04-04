#include "king.h"

King::King(PieceColour colour, int row, int col) : Piece(colour, row, col) {
    if (this->pieceColour() == "black") {
        Positions::setBlackKingPosition({row, col});
    } else {
        Positions::setWhiteKingPosition({row, col});
    }
}

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
    if (this->m_piece == piece) return;
    this->m_piece = piece;
    emit pieceChanged();
}

int King::getScore() {
    return 900;
}
