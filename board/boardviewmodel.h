#ifndef BOARDVIEWMODEL_H
#define BOARDVIEWMODEL_H

#include <QObject>
#include "board/square.h"
#include "board/boardfactory.h"

class BoardViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QList<Square *>> squares READ squares NOTIFY squaresChanged)

    public:
        BoardViewModel();
        QList<QList<Square*>> squares () const { return m_squares; }

    private:
        QList<QList<Square *>> m_squares;

    signals:
        void squaresChanged();
};

#endif // BOARDVIEWMODEL_H
