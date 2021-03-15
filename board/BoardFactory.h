#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H
#include <memory>
#include "board.h"
#include <string>
#include <vector>
class BoardFactory
{
    public:
        static Board * createBoard();

};
#endif // BOARDFACTORY_H
