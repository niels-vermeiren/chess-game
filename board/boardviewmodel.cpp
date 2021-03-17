#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}

QList<QList<int>> BoardViewModel::clickedOnPiece(int row, int col) {
    PawnMove pawnMove;
    QList<QList<int>> posMoves = pawnMove.getPossibleMoves(this->squares()[row][col]->getPieceOnSquare(), this->squares());
    return posMoves;
}
