#include "King.h"

King::King(PieceColour colour) : Piece(colour) {

}
King::~King() {}

QString King::getPieceType() const {
    return QString("♚");
}

QString King::piece() const {
    return this->getPieceType();
};

void King::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
