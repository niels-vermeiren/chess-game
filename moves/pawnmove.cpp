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

    return possibleMoves;
}
