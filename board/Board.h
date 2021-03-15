#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "board/Square.h"

class Board
{
    public:
        Board();
        Board(std::vector<std::vector<std::unique_ptr<Square>>> squares);
        virtual ~Board();

        std::vector<std::vector<std::unique_ptr<Square>>> getSquares();

    private:
        std::vector<std::vector<std::unique_ptr<Square>>> squares;

};

#endif // BOARD_H
