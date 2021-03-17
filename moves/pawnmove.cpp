#include "pawnmove.h"

PawnMove::PawnMove() {}

QList<QList<int>> PawnMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col =piece->getCol();

    //Piece is white and square above is empty
    if(isWhitePiece && row - 1 >= 0 && board[row - 1][col]->getPieceOnSquare()->pieceType() == "") {
        QList<int> move = {row - 1, col};
        possibleMoves.append(move);
    }

    //Piece is black and square below is empty
    if(!isWhitePiece && row + 1 < 8 && board[row + 1][col]->getPieceOnSquare()->pieceType() == "") {
        QList<int> move = {row + 1, col};
        possibleMoves.append(move);
    }

    //Piece is white, is at start position and 2 squares above is empty
    if(isWhitePiece && row == 6 && board[4][col]->getPieceOnSquare()->pieceType() == "") {
        QList<int> move = {4, col};
        possibleMoves.append(move);
    }

    //Piece is black, is at start position and 2 squares below is empty
    if(!isWhitePiece && row == 1 && board[3][col]->getPieceOnSquare()->pieceType() == "") {
        QList<int> move = {3, col};
        possibleMoves.append(move);
    }

    return possibleMoves;
}
