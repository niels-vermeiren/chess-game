#include "pieces/rook.h"

Rook::Rook(PieceColour colour) : Piece(colour)
{
}

Rook::~Rook()
{
    //dtor
}
QString Rook::pieceType() const {
    return QString("♜");
}


QString Rook::piece() const {
    return this->pieceType();
};

void Rook::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
