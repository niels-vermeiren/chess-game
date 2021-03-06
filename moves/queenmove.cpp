#include "queenmove.h"

QueenMove::QueenMove(Piece * piece, QList<QList<Square *>> squares) : Move(piece, squares) {}

QList<QList<int>> QueenMove::getPossibleMoves() {
    QList<QList<int>> possibleMoves;
    const int row = this->piece->getRow();
    const int col = this->piece->getCol();

    //Get all moves on upper left side
    QList<QList<int>> upperLeftMoves = this->getAllMovesInDirection(row, col, -1, -1);
    for(int i = 0; i != upperLeftMoves.count() ; i ++) possibleMoves.append(upperLeftMoves[i]);

    //Get all moves on upper right side
    QList<QList<int>> upperRightMoves = this->getAllMovesInDirection(row, col, -1, 1);
    for(int i = 0; i != upperRightMoves.count() ; i ++) possibleMoves.append(upperRightMoves[i]);

    //Get all moves on lower left side
    QList<QList<int>> lowerLeftMoves = this->getAllMovesInDirection(row, col, 1, -1);
    for(int i = 0; i != lowerLeftMoves.count() ; i ++) possibleMoves.append(lowerLeftMoves[i]);

    //Get all moves on lower right side
    QList<QList<int>> lowerRightMoves = this->getAllMovesInDirection(row, col, 1, 1);
    for(int i = 0; i != lowerRightMoves.count() ; i ++) possibleMoves.append(lowerRightMoves[i]);

    //Get all moves on upper side
    QList<QList<int>> upperMoves = this->getAllMovesInDirection(row, col, -1, 0);
    for(int i = 0; i != upperMoves.count() ; i ++) possibleMoves.append(upperMoves[i]);

    //Get all moves on lower side
    QList<QList<int>> lowerMoves = this->getAllMovesInDirection(row, col, 1, 0);
    for(int i = 0; i != lowerMoves.count() ; i ++) possibleMoves.append(lowerMoves[i]);

    //Get all moves on left side
    QList<QList<int>> leftMoves = this->getAllMovesInDirection(row, col, 0, -1);
    for(int i = 0; i != leftMoves.count() ; i ++) possibleMoves.append(leftMoves[i]);

    //Get all moves on right side
    QList<QList<int>> rightMoves = this->getAllMovesInDirection(row, col, 0, 1);
    for(int i = 0; i != rightMoves.count() ; i ++) possibleMoves.append(rightMoves[i]);

    return possibleMoves;
}
