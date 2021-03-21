#include "game.h"

Game::Game() {}

QList<QList<int>> Game::getPossibleMoves(QList<QList<Square *>> board, int row, int col) {

    Piece * piece = board[row][col]->getPieceOnSquare();

    Move * move = MoveFactory::createMoveStrategy(piece, board);
    QList<QList<int>> posMoves = move->getPossibleMoves();

    //Check if move does not result in a check, if so remove possible move
    int i = 0;
    while(i != posMoves.count()) {
        //Make move and check for check
        if(posMoves[i].count() > 0) {
            //Copy piece
            Piece * pieceClone = board[row][col]->getPieceOnSquare()->clone();
            int posRow = posMoves[i][0];
            int posCol = posMoves[i][1];

            board[row][col]->changePiece("","");
            Piece * capturedPiece = board[posRow][posCol]->getPieceOnSquare()->clone();
            board[posRow][posCol]->changePiece(pieceClone->pieceType(), pieceClone->pieceColour());

            bool isCheck = Game::isCheckForColour(board, pieceClone->pieceColour());

            //Revert move
            board[row][col]->changePiece(pieceClone->pieceType(), pieceClone->pieceColour());
            board[posRow][posCol]->changePiece(capturedPiece->pieceType(), capturedPiece->pieceColour());

            if (!isCheck) i++;
            else posMoves.remove(i);
        }
    }


    return posMoves;
}

bool Game::isCheckForColour(QList<QList<Square *>> board, QString colour) {
    //Get position of black king
    Piece * king;
    bool kingFound = false;
    for(int i = 0; i < board.count(); i++) {
        for(int j = 0; j < board[0].count(); j++) {
            if(board[i][j]->getPieceOnSquare()->pieceType() == "♚" && board[i][j]->getPieceOnSquare()->pieceColour() == colour) {
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
            if(board[i][j]->getPieceOnSquare()->pieceColour( ) == colour) continue;
            Move * move = MoveFactory::createMoveStrategy(board[i][j]->getPieceOnSquare(), board);
            QList<QList<int>> possibleMoves = move->getPossibleMoves();

            for(int k = 0; k != possibleMoves.count(); k++) {
                if(possibleMoves[k].count() > 0) {
                    int possibleRow = possibleMoves[k][0];
                    int possibleCol = possibleMoves[k][1];

                    if(king->getRow() == possibleRow && king->getCol() == possibleCol) return true;
                }
            }
        }
    }

    return false;
}

bool Game::isCheckMateForColour(QList<QList<Square *>> board, QString colour) {
    //Check if black can make any legal move that doesn't result in a check
    //Get all possible moves for black


    for(int i = 0; i < board.count(); i++) {
        for(int j = 0; j < board[0].count(); j++) {
            if(board[i][j]->getPieceOnSquare()->pieceColour() != colour) continue;
            Move * move = MoveFactory::createMoveStrategy(board[i][j]->getPieceOnSquare(), board);
            QList<QList<int>> possibleMoves = move->getPossibleMoves();

            for(int k = 0; k != possibleMoves.count(); k++) {
                //Make the move
                if(possibleMoves[k].count() > 0) {
                    //Copy piece
                    Piece * piece = board[i][j]->getPieceOnSquare()->clone();
                    int row = possibleMoves[k][0];
                    int col = possibleMoves[k][1];

                    board[i][j]->changePiece("","");
                    Piece * capturedPiece = board[row][col]->getPieceOnSquare()->clone();
                    board[row][col]->changePiece(piece->pieceType(), piece->pieceColour());

                    bool isNotCheckMate = false;

                    if(!isCheckForColour(board, colour)) isNotCheckMate = true;

                    //Revert move
                    board[i][j]->changePiece(piece->pieceType(), piece->pieceColour());
                    board[row][col]->changePiece(capturedPiece->pieceType(), capturedPiece->pieceColour());

                    if (isNotCheckMate) return false;

                }
            }
        }
    }
    return true;
}

bool Game::isStaleMateForColour(QList<QList<Square *>> board, QString colour) {

    //If colour has no legal moves, stalemate has occured
    //Get all pieces of colour
    QList<QList<int>> possibleMoves = {{}};
    for (int i = 0; i != board.count(); i++) {
        for(int j = 0; j != board[0].count(); j++) {
            QString pieceColour = board[i][j]->getPieceOnSquare()->pieceColour();
            if(pieceColour != colour) continue;
            QList<QList<int>> posMovesForPiece = Game::getPossibleMoves(board, i, j);
            if(posMovesForPiece.count() > 0) return false;

        }
    }
    return true;
}
