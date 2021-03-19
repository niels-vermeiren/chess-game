#include "bishopmove.h"

BishopMove::BishopMove() {}

QList<QList<int>> BishopMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col = piece->getCol();

    //Get all moves on upper left side
    QList<QList<int>> upperLeftMoves = this->getAllMovesInDirection(isWhitePiece, row, col, -1, -1, board);
    for(int i = 0; i != upperLeftMoves.count() ; i ++) possibleMoves.append(upperLeftMoves[i]);

    //Get all moves on upper right side
    QList<QList<int>> upperRightMoves = this->getAllMovesInDirection(isWhitePiece, row, col, -1, 1, board);
    for(int i = 0; i != upperRightMoves.count() ; i ++) possibleMoves.append(upperRightMoves[i]);

    //Get all moves on lower left side
    QList<QList<int>> lowerLeftMoves = this->getAllMovesInDirection(isWhitePiece, row, col, 1, -1, board);
    for(int i = 0; i != lowerLeftMoves.count() ; i ++) possibleMoves.append(lowerLeftMoves[i]);

    //Get all moves on lower right side
    QList<QList<int>> lowerRightMoves = this->getAllMovesInDirection(isWhitePiece, row, col, 1, 1, board);
    for(int i = 0; i != lowerRightMoves.count() ; i ++) possibleMoves.append(lowerRightMoves[i]);

    return possibleMoves;
}