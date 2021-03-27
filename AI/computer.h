#ifndef COMPUTER_H
#define COMPUTER_H
#include "pieces/piece.h"
#include <QHash>
#include "board/square.h"
#include "moves/movefactory.h"
#include "game/game.h"
#include "AI/boardevaluator.h"
#include "minimax.h"

class Computer : public QObject {
    Q_OBJECT
    private:
        Minimax * minimax;
        QList<QList<Square *>> board;
        void replacePawnWithPiece(Piece * piece, QList<int> move);
    public:
        Computer(QList<QList<Square *>> board);
        virtual ~Computer();
        Q_INVOKABLE void makeMove();
};

#endif // COMPUTER_H
