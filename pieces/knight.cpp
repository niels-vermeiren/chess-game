#include "knight.h"

Knight::Knight(PieceColour colour, int row, int col) : Piece(colour, row, col) {}
Knight::~Knight() {}

Piece * Knight::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    Piece * knight = new Knight(colour, this->getRow(), this->getCol());
    knight->setMoved(this->hasMoved());
    return knight;
}

QString Knight::pieceType() const {
    return QString("♞");
}

void Knight::setPiece(QString piece) {
    if (this->m_piece == piece) return;
    this->m_piece = piece;
    emit pieceChanged();
}
int Knight::getScore() {
    return 30;
}
