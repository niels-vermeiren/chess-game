#include "move.h"

Move::Move() {}

QList<QList<int>> Move::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> move;
    return move;
}

QString Move::getPieceType(QList<QList<Square *>> board, int row, int col) {
    return board[row][col]->getPieceOnSquare()->pieceType();
}

QString Move::getPieceColour(QList<QList<Square *>> board, int row, int col) {
    return board[row][col]->getPieceOnSquare()->pieceColour();
}
