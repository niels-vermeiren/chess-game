#include "Bishop.h"

Bishop::Bishop(PieceColour colour) : Piece(colour) {

}
Bishop::~Bishop() {}

QString Bishop::getPieceType() const {
    return QString("♝");
}
QString Bishop::piece() const {
    return this->getPieceType();
};

void Bishop::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
