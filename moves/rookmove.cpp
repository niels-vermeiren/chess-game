#include "rookmove.h"

RookMove::RookMove(Piece * piece, QList<QList<Square *>> squares) : Move(piece, squares) {}

QList<QList<int>> RookMove::getPossibleMoves() {
    QList<QList<int>> possibleMoves;
    const int row = piece->getRow();
    const int col = piece->getCol();

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

