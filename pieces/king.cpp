#include "king.h"

King::King(PieceColour colour) : Piece(colour) {

}
King::~King() {}

QString King::pieceType() const {
    return QString("♚");
}

QString King::piece() const {
    return this->pieceType();
};

void King::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
