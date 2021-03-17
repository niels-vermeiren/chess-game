#include "bishop.h"

Bishop::Bishop(PieceColour colour, int row, int col) : Piece(colour, row, col) {}

Bishop::~Bishop() {}

QString Bishop::pieceType() const {
    return QString("♝");
}

void Bishop::setPiece(QString piece) {
    if(this->m_piece != piece) {
        this->m_piece = piece;
        emit pieceChanged();
    }
}
