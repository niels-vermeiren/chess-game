#include "move.h"

Move::Move(Piece * piece, QList<QList<Square *>> squares) {
    this->piece = piece;
    this->squares = squares;
}

Move::~Move() {
    delete this->piece;
    for (int i = 0; i != this->squares.count(); i++)
        for (int j = 0 ; j != this->squares[i].count(); j++ )
            delete this->squares[i][j];
}

QList<QList<int>> Move::getPossibleMoves() {
    return {{}};
}

QString Move::getPieceType(int row, int col) {
    return this->squares[row][col]->getPieceOnSquare()->pieceType();
}

QString Move::getPieceColour(int row, int col) {
    return this->squares[row][col]->getPieceOnSquare()->pieceColour();
}

QList<QList<int>> Move::getAllMovesInDirection(int row, int col, int directionRow, int directionCol) {
    bool isWhitePiece = this->piece->pieceColour() == "white";
    QList<QList<int>> possibleMoves;
    int step = 1;
    int stepRow = row + (directionRow * step);
    int stepCol = col + (directionCol * step);

    //Can move to the direction, until it comes accross another piece
    while (stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && getPieceType(stepRow, stepCol)  == "") {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
        step ++;
        stepRow = row + (directionRow * step);
        stepCol = col + (directionCol * step);
    }

    //If one step further is opposite colour piece, give possibility to capture
    if (stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && ((isWhitePiece && getPieceColour(stepRow, stepCol)  == "black")
            || (!isWhitePiece && getPieceColour(stepRow, stepCol)  == "white"))) {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
    }

    return possibleMoves;
}

QList<QList<int>> Move::getOneMoveInDirection(int row, int col, int directionRow, int directionCol) {
    bool isWhitePiece = this->piece->pieceColour() == "white";
    QList<QList<int>> possibleMoves;
    int stepRow = row + directionRow;
    int stepCol = col + directionCol;

    //Piece is white and square in direction is empty or black piece
    if(isWhitePiece && stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && getPieceColour(stepRow, stepCol) != "white") {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
    }

    //Piece is black and square in direction is empty or white piece
    if(!isWhitePiece && stepRow >= 0 && stepRow < 8 && stepCol >= 0 && stepCol < 8 && getPieceColour(stepRow, stepCol) != "black") {
        QList<int> move = {stepRow, stepCol};
        possibleMoves.append(move);
    }

    return possibleMoves;
}
