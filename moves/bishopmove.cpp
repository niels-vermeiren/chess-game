#include "bishopmove.h"

BishopMove::BishopMove() {}
QList<QList<int>> BishopMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col = piece->getCol();
}
