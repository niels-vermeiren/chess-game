#ifndef BOARDVIEWMODEL_H
#define BOARDVIEWMODEL_H

#include <QObject>
#include "board/square.h"
#include "board/boardfactory.h"
#include "moves/pawnmove.h"
#include "moves/movefactory.h"
#include "game/game.h"
#include "AI/computer.h"

class BoardViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QList<Square *>> squares READ squares WRITE setSquares NOTIFY squaresChanged)
    Q_PROPERTY(bool checkForBlack NOTIFY checkForBlackChanged)
    Q_PROPERTY(bool checkMateForBlack NOTIFY checkForBlackChanged)
    Q_PROPERTY(bool checkForWhite NOTIFY checkForWhiteChanged)
    Q_PROPERTY(bool checkMateForWhite NOTIFY checkForWhiteChanged)
    Q_PROPERTY(bool staleMate NOTIFY staleMateChanged)

    public:
        BoardViewModel();
        virtual ~BoardViewModel();
        QList<QList<Square *>> squares () const;
        Q_INVOKABLE QList<QList<int>> clickedOnPiece(int row, int col);
        Q_INVOKABLE void newGame();
        Q_INVOKABLE bool isCheckForColour(QString colour);
        Q_INVOKABLE bool isCheckMateForColour(QString colour);
        Q_INVOKABLE bool isStaleMate();
        Q_INVOKABLE void makeAIMove();

    private:
        QList<QList<Square *>> m_squares;
        void setSquares(QList<QList<Square *>> squares);
        Computer * blackPlayer;

    signals:
        void squaresChanged();
        void checkForBlackChanged();
        void checkMateForBlackChanged();
        void checkForWhiteChanged();
        void checkMateForWhiteChanged();
        void staleMateChanged();
};

#endif // BOARDVIEWMODEL_H
