#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}

QList<QList<int>> BoardViewModel::clickedOnPiece(int row, int col) {
    Piece * piece = this->squares()[row][col]->getPieceOnSquare();
    Move * move = MoveFactory::createMoveStrategy(piece);
    QList<QList<int>> posMoves = move->getPossibleMoves(piece, this->squares());
    return posMoves;
}
