#include "kingmove.h"

KingMove::KingMove() {}

QList<QList<int>> KingMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
        QList<QList<int>> possibleMoves;
        const bool isWhitePiece = piece->pieceColour() == "white";
        const int row = piece->getRow();
        const int col = piece->getCol();

        //Get all moves on upper left side
        QList<QList<int>> upperLeftMoves = this->getOneMoveInDirection(isWhitePiece, row, col, -1, -1, board);
        for(int i = 0; i != upperLeftMoves.count() ; i ++) possibleMoves.append(upperLeftMoves[i]);

        //Get all moves on upper right side
        QList<QList<int>> upperRightMoves = this->getOneMoveInDirection(isWhitePiece, row, col, -1, 1, board);
        for(int i = 0; i != upperRightMoves.count() ; i ++) possibleMoves.append(upperRightMoves[i]);

        //Get all moves on lower left side
        QList<QList<int>> lowerLeftMoves = this->getOneMoveInDirection(isWhitePiece, row, col, 1, -1, board);
        for(int i = 0; i != lowerLeftMoves.count() ; i ++) possibleMoves.append(lowerLeftMoves[i]);

        //Get all moves on lower right side
        QList<QList<int>> lowerRightMoves = this->getOneMoveInDirection(isWhitePiece, row, col, 1, 1, board);
        for(int i = 0; i != lowerRightMoves.count() ; i ++) possibleMoves.append(lowerRightMoves[i]);

        //Get all moves on upper side
        QList<QList<int>> upperMoves = this->getOneMoveInDirection(isWhitePiece, row, col, -1, 0, board);
        for(int i = 0; i != upperMoves.count() ; i ++) possibleMoves.append(upperMoves[i]);

        //Get all moves on lower side
        QList<QList<int>> lowerMoves = this->getOneMoveInDirection(isWhitePiece, row, col, 1, 0, board);
        for(int i = 0; i != lowerMoves.count() ; i ++) possibleMoves.append(lowerMoves[i]);

        //Get all moves on left side
        QList<QList<int>> leftMoves = this->getOneMoveInDirection(isWhitePiece, row, col, 0, -1, board);
        for(int i = 0; i != leftMoves.count() ; i ++) possibleMoves.append(leftMoves[i]);

        //Get all moves on right side
        QList<QList<int>> rightMoves = this->getOneMoveInDirection(isWhitePiece, row, col, 0, 1, board);
        for(int i = 0; i != rightMoves.count() ; i ++) possibleMoves.append(rightMoves[i]);

        return possibleMoves;
}
