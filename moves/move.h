#ifndef MOVE_H
#define MOVE_H

#include <QObject>
#include "moves/possiblemove.h"
#include "board/square.h"

class Move : public QObject
{
    Q_OBJECT
public:
    Move();
    Q_INVOKABLE virtual QList<PossibleMove *> getPossibleMoves(const int x, const int y, const QList<QList<Square *>> board);

signals:

};

#endif // MOVE_H
