#include "pieces/Rook.h"

Rook::Rook(PieceColour colour) : Piece(colour)
{
}

Rook::~Rook()
{
    //dtor
}
QString Rook::getPieceType() const {
    return QString("♜");
}


QString Rook::piece() const {
    return this->getPieceType();
};

void Rook::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
