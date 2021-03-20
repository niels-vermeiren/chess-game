#include "knightmove.h"

KnightMove::KnightMove(Piece * piece, QList<QList<Square *>> squares) : Move(piece, squares) {}

QList<QList<int>> KnightMove::getPossibleMoves() {
    QList<QList<int>> possibleMoves;
    const int row = this->piece->getRow();
    const int col = this->piece->getCol();

    //Two squares up and one square left is free opposite colour
    QList<QList<int>> upperLeftMoves = this->getOneMoveInDirection(row, col, -2, -1);
    if (upperLeftMoves.count() > 0) possibleMoves.append(upperLeftMoves[0]);

    //Two squares up and one square right is free opposite colour
    QList<QList<int>> upperRightMoves = this->getOneMoveInDirection(row, col, -2, 1);
    if (upperRightMoves.count() > 0) possibleMoves.append(upperRightMoves[0]);

    //One square up and two squares right is free opposite colour
    QList<QList<int>> rightUpMoves = this->getOneMoveInDirection(row, col, -2, 1);
    if (rightUpMoves.count() > 0) possibleMoves.append(rightUpMoves[0]);

    //One square down and two squares right is free opposite colour
    QList<QList<int>> rightDownMoves = this->getOneMoveInDirection(row, col, 1, 2);
    if (rightDownMoves.count() > 0) possibleMoves.append(rightDownMoves[0]);

    //Two squares down and one square left is free opposite colour
    QList<QList<int>> bottomLeftMoves = this->getOneMoveInDirection(row, col, 2, -1);
    if (bottomLeftMoves.count() > 0) possibleMoves.append(bottomLeftMoves[0]);

    //Two squares down and one square right is free opposite colour
    QList<QList<int>> bottomRightMoves = this->getOneMoveInDirection(row, col, 2, 1);
    if (bottomRightMoves.count() > 0) possibleMoves.append(bottomRightMoves[0]);

    //One square up and two squares left is free opposite colour
    QList<QList<int>> leftUpMoves = this->getOneMoveInDirection(row, col, -1, -2);
    if (leftUpMoves.count() > 0) possibleMoves.append(leftUpMoves[0]);

    //One square down and two squares left is free opposite colour
    QList<QList<int>> leftDownMoves = this->getOneMoveInDirection(row, col, 1, -2);
    if (leftDownMoves.count() > 0) possibleMoves.append(leftDownMoves[0]);

    return possibleMoves;
}
