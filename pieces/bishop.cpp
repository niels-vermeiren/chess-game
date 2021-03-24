#include "bishop.h"

Bishop::Bishop(PieceColour colour, int row, int col) : Piece(colour, row, col) {}
Bishop::~Bishop() {}

Piece * Bishop::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    Piece * bishop =  new Bishop(colour, this->getRow(), this->getCol());
    bishop->setMoved(this->hasMoved());
    return bishop;
}

QString Bishop::pieceType() const {
    return QString("♝");
}

void Bishop::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
