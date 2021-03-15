#include "Queen.h"

Queen::Queen(PieceColour colour) : Piece(colour) {
}
Queen::~Queen() {}
QString Queen::getPieceType() const {
    return QString("♛");
}
QString Queen::piece() const {
    return this->getPieceType();
};

void Queen::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
