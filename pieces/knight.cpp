#include "knight.h"

Knight::Knight(PieceColour colour) : Piece(colour) {
}
Knight::~Knight() {}

QString Knight::pieceType() const {
    return QString("♞");
}
QString Knight::piece() const {
    return QString("♞");
};

void Knight::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
