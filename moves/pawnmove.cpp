#include "pawnmove.h"

PawnMove::PawnMove() {}

QList<QList<int>> PawnMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col =piece->getCol();

    //Piece is white and square above is empty
    if(isWhitePiece && row - 1 >= 0 && getPieceType(board, row - 1, col) == "") {
        QList<int> move = {row - 1, col};
        possibleMoves.append(move);
    }

    //Piece is black and square below is empty
    if(!isWhitePiece && row + 1 < 8 && getPieceType(board, row + 1, col) == "") {
        QList<int> move = {row + 1, col};
        possibleMoves.append(move);
    }

    //Piece is white, is at start position and 2 squares above is empty
    if(isWhitePiece && row == 6 && getPieceType(board, 4, col) == "") {
        QList<int> move = {4, col};
        possibleMoves.append(move);
    }

    //Piece is black, is at start position and 2 squares below is empty
    if(!isWhitePiece && row == 1 && getPieceType(board, 3, col) == "") {
        QList<int> move = {3, col};
        possibleMoves.append(move);
    }

    //If piece is white and there is a black piece on the upper left, white piece can capture
    if(isWhitePiece && row - 1 >= 0 && col - 1 >=0 && getPieceColour(board, row - 1, col - 1) == "black") {
        QList<int> move = {row - 1, col - 1};
        possibleMoves.append(move);
    }

    //If piece is white and there is a black piece on the upper right, white piece can capture
    if(isWhitePiece && row - 1 >= 0 && col + 1 < 8 && getPieceColour(board, row - 1, col + 1) == "black") {
        QList<int> move = {row - 1, col + 1};
        possibleMoves.append(move);
    }

    //If piece is black and there is a white piece on the lower left, black piece can capture
    if(!isWhitePiece && row + 1 < 8 && col - 1 >= 0  && getPieceColour(board, row + 1, col - 1) == "white") {
        QList<int> move = {row + 1, col - 1};
        possibleMoves.append(move);
    }

    //If piece is black and there is a black piece on the lower right, black piece can capture
    if(!isWhitePiece && row + 1 < 8 && col + 1 < 8 && getPieceColour(board, row + 1, col + 1) == "white") {
        QList<int> move = {row + 1, col + 1};
        possibleMoves.append(move);
    }

    return possibleMoves;
}
