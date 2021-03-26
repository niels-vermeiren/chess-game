#include "game.h"

Game::Game() {}

QList<QList<int>> Game::getPossibleMoves(QList<QList<Square *>> board, int row, int col) {
    QList<QList<int>> possibleMoves;
    Piece * pieceClone = board[row][col]->getPieceOnSquare()->clone();
    if (pieceClone->pieceType() == "") return possibleMoves;
    Move * move = MoveFactory::createMoveStrategy(pieceClone, board);
    possibleMoves = move->getPossibleMoves();

    //Check if move does not result in a check, if so remove possible move
    int i = 0;
    while(i != possibleMoves.count()) {
        //Make move and check for check
        if(possibleMoves[i].count() > 0) {
            bool isCheck = false;
            //Make move
            Piece * capturedPiece = makeMove(board, pieceClone, possibleMoves[i])->clone();
            isCheck = isCheckForColour(board, pieceClone->pieceColour());
            //Revert move
            undoMove(board, pieceClone, capturedPiece, row, col);
            if (!isCheck) i++;
            else possibleMoves.remove(i);
        }
    }
    return possibleMoves;
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
    //Check if colour can make any legal move that doesn't result in a check
    //Get all possible moves for colour
    for(int i = 0; i < board.count(); i++) {
        for(int j = 0; j < board[0].count(); j++) {
            if(board[i][j]->getPieceOnSquare()->pieceColour() != colour) continue;
            Move * move = MoveFactory::createMoveStrategy(board[i][j]->getPieceOnSquare(), board);
            QList<QList<int>> possibleMoves = move->getPossibleMoves();

            for(int k = 0; k != possibleMoves.count(); k++) {
                //Make the move
                bool isNotCheckMate = false;
                if(possibleMoves[k].count() > 0) {
                    //Copy piece
                    Piece * piece = board[i][j]->getPieceOnSquare()->clone();

                    //If it is a castling move
                    if(isCastlingMove(piece, possibleMoves[k])) {
                        piece = castle(board, piece, possibleMoves[k]);
                        isNotCheckMate = !isCheckForColour(board, piece->pieceColour());
                        reverseCastle(board, piece);
                    } else {
                        //Move
                        Piece * capturedPiece = makeMove(board, piece, possibleMoves[k]);
                        isNotCheckMate = !isCheckForColour(board, colour);
                        undoMove(board, piece, capturedPiece, i, j);
                        //Revert move
                    }
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
            QList<QList<int>> posMovesForPiece = getPossibleMoves(board, i, j);
            if(posMovesForPiece.count() > 0) return false;

        }
    }
    return true;
}

bool Game::isCastlingMove(Piece * piece, QList<int> possibleMove) {
    return piece->pieceType() == "♚" && (isLeftCastlingMove(piece, possibleMove) || isRightCastlingMove(piece, possibleMove));
}

bool Game::isLeftCastlingMove(Piece * piece, QList<int> possibleMove) {
    return piece->getCol() - 2 == possibleMove[1];
}

bool Game::isRightCastlingMove(Piece * piece, QList<int> possibleMove) {
    return piece->getCol() + 2 == possibleMove[1];
}

Piece * Game::makeMove(QList<QList<Square *>> board, Piece * piece, QList<int> possibleMove) {
    int row = piece->getRow();
    int col = piece->getCol();
    board[row][col]->changePiece("","", false);
    Piece * capturedPiece = board[possibleMove[0]][possibleMove[1]]->getPieceOnSquare()->clone();
    board[possibleMove[0]][possibleMove[1]]->changePiece(piece->pieceType(), piece->pieceColour(), capturedPiece->hasMoved());
    return capturedPiece;
};

void Game::undoMove(QList<QList<Square *>> board, Piece * piece, Piece * capturedPiece, int row, int col) {
    board[row][col]->changePiece(piece->pieceType(), piece->pieceColour(), piece->hasMoved());
    board[capturedPiece->getRow()][capturedPiece->getCol()]->changePiece(capturedPiece->pieceType(), capturedPiece->pieceColour(), capturedPiece->hasMoved());
};

Piece * Game::castle(QList<QList<Square *>> board, Piece * piece, QList<int> possibleMove) {
    //If is a castling move (col should differ 2 from possibleMoveCole
    //Check which rook the king is castling to
    //Left rook?
    if(isLeftCastlingMove(piece, possibleMove) && board[piece->getRow()][0]->getPieceOnSquare()->pieceType() == "♜") {
        //Move king two to the left
        board[piece->getRow()][piece->getCol()]->changePiece("", "", false);
        board[piece->getRow()][piece->getCol() - 2]->changePiece(piece->pieceType(), piece->pieceColour(), piece->hasMoved());

        piece = board[piece->getRow()][piece->getCol() - 2]->getPieceOnSquare()->clone();
        //Move rook to the right side of king
        board[piece->getRow()][0]->changePiece("", "", false);
        board[piece->getRow()][2]->changePiece("♜", piece->pieceColour(), piece->hasMoved());

    } else if (isRightCastlingMove(piece, possibleMove) && board[piece->getRow()][7]->getPieceOnSquare()->pieceType() == "♜") {
        //Move king two to the left
        board[piece->getRow()][piece->getCol()]->changePiece("", "", false);
        board[piece->getRow()][piece->getCol() + 2]->changePiece(piece->pieceType(), piece->pieceColour(), piece->hasMoved());

        piece = board[piece->getRow()][piece->getCol() + 2]->getPieceOnSquare()->clone();
        //Move rook to the right side of king
        board[piece->getRow()][7]->changePiece("", "", false);
        board[piece->getRow()][4]->changePiece("♜", piece->pieceColour(), piece->hasMoved());

    }
    return piece;
}

void Game::reverseCastle(QList<QList<Square*>> board, Piece * piece) {
    //King has castled, reverse it
    //If king has castled to the left
    if(piece->getCol() == 1) {
        //Move king to original position
        board[piece->getRow()][piece->getCol()]->changePiece("", "", false);
        board[piece->getRow()][3]->changePiece(piece->pieceType(), piece->pieceColour(), piece->hasMoved());

        //Move rook to the original position
        board[piece->getRow()][2]->changePiece("", "", false);
        board[piece->getRow()][0]->changePiece("♜", piece->pieceColour(), piece->hasMoved());

    //If king has castled to the right
    } else if (piece->getCol() == 5) {
        //Move king to original position
        board[piece->getRow()][piece->getCol()]->changePiece("", "", false);
        board[piece->getRow()][3]->changePiece(piece->pieceType(), piece->pieceColour(), piece->hasMoved());

        //Move rook to the original position
        board[piece->getRow()][4]->changePiece("", "", false);
        board[piece->getRow()][7]->changePiece("♜", piece->pieceColour(), piece->hasMoved());
    }
}
