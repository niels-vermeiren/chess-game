#include "knightmove.h"

KnightMove::KnightMove() {}

QList<QList<int>> KnightMove::getPossibleMoves(Piece * piece, QList<QList<Square *>> board) {
    QList<QList<int>> possibleMoves;
    const bool isWhitePiece = piece->pieceColour() == "white";
    const int row = piece->getRow();
    const int col = piece->getCol();

    //Knight is white, and two squares up and one square left is free or black
    if(isWhitePiece && row - 2 >= 0 && col - 1 >= 0 && getPieceColour(board, row - 2, col - 1) != "white") {
        QList<int> move = {row - 2, col -  1};
        possibleMoves.append(move);
    }

    //Knight is white, and two squares up and one square right is free or black
    if(isWhitePiece && row - 2 >= 0 && col + 1 < 8 && getPieceColour(board, row - 2, col + 1) != "white") {
        QList<int> move = {row - 2, col + 1};
        possibleMoves.append(move);
    }

    //Knight is white, and one square up and two squares right is free or black
    if(isWhitePiece && row - 1 >= 0 && col + 2 < 8 && getPieceColour(board, row - 1, col + 2) != "white") {
        QList<int> move = {row - 1, col + 2};
        possibleMoves.append(move);
    }

    //Knight is white, and one square down and two squares right is free or black
    if(isWhitePiece && row + 1 < 8 && col + 2 < 8 && getPieceColour(board, row + 1, col + 2) != "white") {
        QList<int> move = {row + 1, col + 2};
        possibleMoves.append(move);
    }

    //Knight is white, and two squares down and one square left is free or black
    if(isWhitePiece && row + 2 < 8 && col - 1 >= 0 && getPieceColour(board, row + 2, col - 1) != "white") {
        QList<int> move = {row + 2, col -  1};
        possibleMoves.append(move);
    }

    //Knight is white, and two squares down and one square right is free or black
    if(isWhitePiece && row + 2 < 8 && col + 1 < 8 && getPieceColour(board, row + 2, col + 1) != "white") {
        QList<int> move = {row + 2, col + 1};
        possibleMoves.append(move);
    }

    //Knight is white, and one square up and two squares left is free or black
    if(isWhitePiece && row - 1 >= 0 && col - 2 >= 0 && getPieceColour(board, row - 1, col - 2) != "white") {
        QList<int> move = {row - 1, col - 2};
        possibleMoves.append(move);
    }

    //Knight is white, and one square down and two squares left is free or black
    if(isWhitePiece && row + 1 < 8 && col - 2 >= 0 && getPieceColour(board, row + 1, col - 2) != "white") {
        QList<int> move = {row + 1, col - 2};
        possibleMoves.append(move);
    }

    //Knight is black, and two squares up and one square left is free or white
    if(!isWhitePiece && row - 2 >= 0 && col - 1 >= 0 && getPieceColour(board, row - 2, col - 1) != "black") {
        QList<int> move = {row - 2, col -  1};
        possibleMoves.append(move);
    }

    //Knight is black, and two squares up and one square right is free or white
    if(!isWhitePiece && row - 2 >= 0 && col + 1 < 8 && getPieceColour(board, row - 2, col + 1) != "black") {
        QList<int> move = {row - 2, col + 1};
        possibleMoves.append(move);
    }

    //Knight is black, and one square up and two squares right is free or white
    if(!isWhitePiece && row - 1 >= 0 && col + 2 < 8 && getPieceColour(board, row - 1, col + 2) != "black") {
        QList<int> move = {row - 1, col + 2};
        possibleMoves.append(move);
    }

    //Knight is black, and one square down and two squares right is free or white
    if(!isWhitePiece && row + 1 < 8 && col + 2 < 8 && getPieceColour(board, row + 1, col + 2) != "black") {
        QList<int> move = {row + 1, col + 2};
        possibleMoves.append(move);
    }

    //Knight is black, and two squares down and one square left is free or white
    if(!isWhitePiece && row + 2 < 8 && col - 1 >= 0 && getPieceColour(board, row + 2, col - 1) != "black") {
        QList<int> move = {row + 2, col -  1};
        possibleMoves.append(move);
    }

    //Knight is black, and two squares down and one square right is free or white
    if(!isWhitePiece && row + 2 < 8 && col + 1 < 8 && getPieceColour(board, row + 2, col + 1) != "black") {
        QList<int> move = {row + 2, col + 1};
        possibleMoves.append(move);
    }

    //Knight is black, and one square up and two squares left is free or white
    if(!isWhitePiece && row - 1 >= 0 && col - 2 >= 0 && getPieceColour(board, row - 1, col - 2) != "black") {
        QList<int> move = {row - 1, col - 2};
        possibleMoves.append(move);
    }

    //Knight is black, and one square down and two squares left is free or white
    if(!isWhitePiece && row + 1 < 8 && col - 2 >= 0 && getPieceColour(board, row + 1, col - 2) != "black") {
        QList<int> move = {row + 1, col - 2};
        possibleMoves.append(move);
    }

    return possibleMoves;
}
