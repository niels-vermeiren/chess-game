#include "kingmove.h"

KingMove::KingMove(Piece * piece, QList<QList<Square *>> squares) : Move(piece, squares) {}

QList<QList<int>> KingMove::getPossibleMoves() {
        QList<QList<int>> possibleMoves;
        const int row = piece->getRow();
        const int col = piece->getCol();

        //Get all moves on upper left side
        QList<QList<int>> upperLeftMoves = this->getOneMoveInDirection(row, col, -1, -1);
        if(upperLeftMoves.count() > 0) possibleMoves.append(upperLeftMoves[0]);

        //Get all moves on upper right side
        QList<QList<int>> upperRightMoves = this->getOneMoveInDirection(row, col, -1, 1);
        if(upperRightMoves.count() > 0) possibleMoves.append(upperRightMoves[0]);

        //Get all moves on lower left side
        QList<QList<int>> lowerLeftMoves = this->getOneMoveInDirection(row, col, 1, -1);
        if(lowerLeftMoves.count() > 0) possibleMoves.append(lowerLeftMoves[0]);

        //Get all moves on lower right side
        QList<QList<int>> lowerRightMoves = this->getOneMoveInDirection(row, col, 1, 1);
        if(lowerRightMoves.count() > 0) possibleMoves.append(lowerRightMoves[0]);

        //Get all moves on upper side
        QList<QList<int>> upperMoves = this->getOneMoveInDirection(row, col, -1, 0);
        if(upperMoves.count() > 0) possibleMoves.append(upperMoves[0]);

        //Get all moves on lower side
        QList<QList<int>> lowerMoves = this->getOneMoveInDirection(row, col, 1, 0);
        if(lowerMoves.count() > 0) possibleMoves.append(lowerMoves[0]);

        //Get all moves on left side
        QList<QList<int>> leftMoves = this->getOneMoveInDirection(row, col, 0, -1);
        if(leftMoves.count() > 0) possibleMoves.append(leftMoves[0]);

        //Get all moves on right side
        QList<QList<int>> rightMoves = this->getOneMoveInDirection(row, col, 0, 1);
        if(rightMoves.count() > 0) possibleMoves.append(rightMoves[0]);

        return possibleMoves;
}
