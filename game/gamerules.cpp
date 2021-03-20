#include "gamerules.h"

GameRules::GameRules() {}

bool GameRules::isCheckForBlack(QList<QList<Square *>> board) {
    //Get position of black king
    Piece * king;
    bool kingFound = false;
    for(int i = 0; i < board.count(); i++) {
        for(int j = 0; j < board[0].count(); j++) {
            if(board[i][j]->getPieceOnSquare()->pieceType() == "♚" && board[i][j]->getPieceOnSquare()->pieceColour() == "black") {
                king = board[i][j]->getPieceOnSquare();
                kingFound = true;
                break;
            }
        }
        if (kingFound) break;
    }

    //Check if white can make a move that captures black king
    for(int i = 0; i < board.count() && kingFound; i++) {
        for(int j = 0; j < board[0].count(); j++) {
            if(board[i][j]->getPieceOnSquare()->pieceColour()=="black") continue;
            Move * move = MoveFactory::createMoveStrategy(board[i][j]->getPieceOnSquare(), board);
            QList<QList<int>> possibleMoves = move->getPossibleMoves();

            for(int k = 0; k != possibleMoves.count(); k++) {
                if(possibleMoves[k].count() > 0) {
                    int possibleRow = possibleMoves[k][0];
                    int possibleCol = possibleMoves[k][1];

                    if(king->getRow() == possibleRow && king->getCol() == possibleCol) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool GameRules::isCheckMateForBlack(QList<QList<Square *>> board) {
    //Check if black can make any legal move that doesn't result in a check

    return false;
}
