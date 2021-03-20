#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}

QList<QList<int>> BoardViewModel::clickedOnPiece(int row, int col) {
    QList<QList<Square *>> squaresPiece = this->squares();
    Piece * piece = this->squares()[row][col]->getPieceOnSquare();
    Move * move = MoveFactory::createMoveStrategy(piece, squaresPiece);
    QList<QList<int>> posMoves = move->getPossibleMoves();
    return posMoves;
}

void BoardViewModel::newGame() {
    this->setSquares(BoardFactory::createBoard());
}

void BoardViewModel::setSquares(QList<QList<Square *>> squares) {
    this->m_squares = squares;
    emit squaresChanged();
}

bool BoardViewModel::isCheckForBlack() {
    bool res = GameRules::isCheckForBlack(this->squares());
    emit checkForBlackChanged();
    return res;
}
