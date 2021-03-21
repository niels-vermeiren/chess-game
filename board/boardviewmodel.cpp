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

bool BoardViewModel::isCheckForColour(QString colour) {
    bool res = GameRules::isCheckForColour(this->squares(), colour);
    if (colour == "black") emit checkForBlackChanged();
    else emit checkForWhiteChanged();
    return res;
}

bool BoardViewModel::isCheckMateForColour(QString colour) {
    bool res = GameRules::isCheckMateForColour(this->squares(), colour);
    if (colour == "black") emit checkMateForBlackChanged();
    else emit checkMateForWhiteChanged();
    return res;
}
