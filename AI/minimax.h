#ifndef MINIMAX_H
#define MINIMAX_H
#include "pieces/piece.h"
#include "board/square.h"
#include "boardevaluator.h"
#include <QHash>
#include "game/game.h"

class Minimax {
    public:
        Minimax(QList<QList<Square *>> board);
        int minimax(int depth, QList<QList<Square *>> board, int alpha, int beta, bool isMaximizingPlayer);
        QHash<Piece *, QList<QList<int>>> getNextMoves(QString colour);
        QHash<Piece *, QList<int>> minimaxRoot(int depth);
    private:
        QList<QList<Square *>> board;
};

#endif // MINIMAX_H
