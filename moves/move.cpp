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

QList<QList<int>> Move::getAllMovesInDirection(bool isWhitePiece, int row, int col, int directionRow, int directionCol, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    int step = 1;
    int stepRow = row + (directionRow * step);
    int stepCol = col + (directionCol * step);

    //Bishop can move to the direction, until it comes accross another piece
    while (stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && getPieceType(board, stepRow, stepCol)  == "") {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
        step ++;
        stepRow = row + (directionRow * step);
        stepCol = col + (directionCol * step);
    }

    //If one step further is opposite colour piece, give possibility to capture
    if (stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && ((isWhitePiece && getPieceColour(board, stepRow, stepCol)  == "black")
            || (!isWhitePiece && getPieceColour(board, stepRow, stepCol)  == "white"))) {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
    }

    return possibleMoves;
}
