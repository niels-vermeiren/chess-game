#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H
#include <memory>
#include "board.h"
#include <string>
#include <vector>
class BoardFactory
{
    public:
        static QList<QList<Square *>> createBoard();

};
#endif // BOARDFACTORY_H
