#include "board/Board.h"

Board::Board() {}

Board::Board(std::vector<std::vector<std::unique_ptr<Square>>> squares)
{
    this->squares = std::move(squares);
}

std::vector<std::vector<std::unique_ptr<Square>>> Board::getSquares() {
    return this->squares;
}

Board::~Board()
{

}
