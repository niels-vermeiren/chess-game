#ifndef BOARDVIEWMODEL_H
#define BOARDVIEWMODEL_H

#include <QObject>
#include "board/square.h"
#include "board/boardfactory.h"
#include "moves/pawnmove.h"
#include "moves/movefactory.h"
#include "game/gamerules.h"

class BoardViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QList<Square *>> squares READ squares WRITE setSquares NOTIFY squaresChanged)
    Q_PROPERTY(bool checkForBlack READ isCheckForBlack NOTIFY checkForBlackChanged)
    Q_PROPERTY(bool checkMateForBlack READ isCheckMateForBlack NOTIFY checkForBlackChanged)

    public:
        BoardViewModel();
        QList<QList<Square *>> squares () const;
        Q_INVOKABLE QList<QList<int>> clickedOnPiece(int row, int col);
        Q_INVOKABLE void newGame();
        Q_INVOKABLE bool isCheckForBlack();
        Q_INVOKABLE bool isCheckMateForBlack();

    private:
        QList<QList<Square *>> m_squares;
        void setSquares(QList<QList<Square *>> squares);

    signals:
        void squaresChanged();
        void checkForBlackChanged();
        void checkMateForBlackChanged();
};

#endif // BOARDVIEWMODEL_H
