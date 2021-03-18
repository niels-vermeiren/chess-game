#include "bishopmove.h"

BishopMove::BishopMove() {}
QList<QList<int>> BishopMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col = piece->getCol();

    //Get all moves on upper left side
    QList<QList<int>> upperLeftMoves = this->getMoves(isWhitePiece, row, col, -1, -1, board);
    for(int i = 0; i != upperLeftMoves.count() ; i ++) possibleMoves.append(upperLeftMoves[i]);

    //Get all moves on upper right side
    QList<QList<int>> upperRightMoves = this->getMoves(isWhitePiece, row, col, -1, 1, board);
    for(int i = 0; i != upperRightMoves.count() ; i ++) possibleMoves.append(upperRightMoves[i]);

    //Get all moves on lower left side
    QList<QList<int>> lowerLeftMoves = this->getMoves(isWhitePiece, row, col, 1, -1, board);
    for(int i = 0; i != lowerLeftMoves.count() ; i ++) possibleMoves.append(lowerLeftMoves[i]);

    //Get all moves on lower right side
    QList<QList<int>> lowerRightMoves = this->getMoves(isWhitePiece, row, col, 1, 1, board);
    for(int i = 0; i != lowerRightMoves.count() ; i ++) possibleMoves.append(lowerRightMoves[i]);

    return possibleMoves;
}

QList<QList<int>> BishopMove::getMoves(bool isWhitePiece, int row, int col, int directionRow, int directionCol, QList<QList<Square *>> board) {
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
