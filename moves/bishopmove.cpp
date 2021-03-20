#include "bishopmove.h"

BishopMove::BishopMove(Piece * piece, QList<QList<Square *>> squares): Move(piece, squares) {}

QList<QList<int>> BishopMove::getPossibleMoves() {
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

    return possibleMoves;
}
