#ifndef BOARDEVALUATOR_H
#define BOARDEVALUATOR_H
#include "board/square.h"

class BoardEvaluator
{
public:
    BoardEvaluator();
    static int evaluateBoard(QList<QList<Square *>> board);
};

#endif // BOARDEVALUATOR_H
