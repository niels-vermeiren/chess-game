#include "Knight.h"

Knight::Knight(PieceColour colour) : Piece(colour) {
}
Knight::~Knight() {}

QString Knight::getPieceType() const {
    return QString("♞");
}
QString Knight::piece() const {
    return this->getPieceType();
};

void Knight::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
