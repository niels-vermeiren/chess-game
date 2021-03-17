#ifndef BOARDVIEWMODEL_H
#define BOARDVIEWMODEL_H

#include <QObject>
#include "board/square.h"
#include "board/boardfactory.h"
#include "moves/pawnmove.h"
#include "moves/movefactory.h"

class BoardViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QList<Square *>> squares READ squares NOTIFY squaresChanged)

    public:
        BoardViewModel();
        QList<QList<Square *>> squares () const;
        Q_INVOKABLE QList<QList<int>> clickedOnPiece(int row, int col);

    private:
        QList<QList<Square *>> m_squares;

    signals:
        void squaresChanged();
};

#endif // BOARDVIEWMODEL_H
