#ifndef BOARDEVALUATOR_H
#define BOARDEVALUATOR_H
#include "board/square.h"
#include <algorithm>
class BoardEvaluator {
    public:
        BoardEvaluator();
        static int evaluateBoard(QList<QList<Square *>> board);

    private:
        static QList<QList<double>> pawnWhiteTable;
        static QList<QList<double>> pawnBlackTable;
        static QList<QList<double>> knightTable;
        static QList<QList<double>> bishopWhiteTable;
        static QList<QList<double>> bishopBlackTable;
        static QList<QList<double>> rookWhiteTable;
        static QList<QList<double>> rookBlackTable;
        static QList<QList<double>> queenTable;
        static QList<QList<double>> kingWhiteTable;
        static QList<QList<double>> kingBlackTable;
};

#endif // BOARDEVALUATOR_H
