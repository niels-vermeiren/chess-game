#ifndef COMPUTER_H
#define COMPUTER_H
#include "pieces/piece.h"
#include <QHash>
#include "board/square.h"
#include "moves/movefactory.h"
#include "game/game.h"
#include "AI/boardevaluator.h"

class Computer : public QObject {
    Q_OBJECT
    private:
        QList<QList<Square *>> board;
        void replacePawnWithPiece(Piece * piece, QList<int> move);
        QHash<Piece *, QList<int>> getBestMove();
        QHash<Piece *, QList<int>> getRandomMove();
    public:
        Computer(QList<QList<Square *>> board);
        Q_INVOKABLE void makeMove();
};

#endif // COMPUTER_H
