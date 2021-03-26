#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
    this->blackPlayer = new Computer(this->m_squares);
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}

QList<QList<int>> BoardViewModel::clickedOnPiece(int row, int col) {
    return Game::getPossibleMoves(this->squares(), row, col);
}

void BoardViewModel::newGame() {
    this->setSquares(BoardFactory::createBoard());
    this->blackPlayer = new Computer(this->squares());
}

void BoardViewModel::setSquares(QList<QList<Square *>> squares) {
    this->m_squares = squares;
    emit squaresChanged();
}

bool BoardViewModel::isCheckForColour(QString colour) {
    bool res = Game::isCheckForColour(this->squares(), colour);
    if (colour == "black") emit checkForBlackChanged();
    else emit checkForWhiteChanged();
    return res;
}

bool BoardViewModel::isCheckMateForColour(QString colour) {
    bool res = Game::isCheckMateForColour(this->squares(), colour);
    if (colour == "black") emit checkMateForBlackChanged();
    else emit checkMateForWhiteChanged();
    return res;
}

bool BoardViewModel::isStaleMate() {
    if(Game::isStaleMateForColour(this->squares(), "black") || Game::isStaleMateForColour(this->squares(), "white")) {
        emit staleMateChanged();
        return true;
    }
    return false;
}

void BoardViewModel::makeAIMove() {
    this->blackPlayer->makeMove();
}

BoardViewModel::~BoardViewModel() {
    delete this->blackPlayer;
}
