#include "board.h"
Board::Board(){}

QVector<QVector<std::shared_ptr<Square>>> &Board::squares(){
    return this->m_squares;
};

void Board::setSquares(QVector<QVector<std::shared_ptr<Square>>> &squares) {
    this->m_squares = squares;
}
