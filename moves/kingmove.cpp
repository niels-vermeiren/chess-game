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

        //Castle move
        //If rook hasn't moved yet, and king hasn't moved yet
        //Left rook
        if(!this->piece->hasMoved() && !this->squares[row][0]->getPieceOnSquare()->hasMoved()) {
            //If there are no pieces between king and rook
            if(squares[row][1]->getPieceOnSquare()->pieceType() == "" && squares[row][2]->getPieceOnSquare()->pieceType() == "" && squares[row][3]->getPieceOnSquare()->pieceType() == "") {
                //Move king to square 1
                possibleMoves.append({row, col - 2});
            }
        }

        //Right rook
        if(!this->piece->hasMoved() && !this->squares[row][7]->getPieceOnSquare()->hasMoved()) {
            //If there are no pieces between king and rook
            if(squares[row][6]->getPieceOnSquare()->pieceType() == "" && squares[row][5]->getPieceOnSquare()->pieceType() == "") {
                //Move king to square 1
                possibleMoves.append({row, col + 2});
            }
        }

        return possibleMoves;
}

