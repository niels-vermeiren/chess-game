#ifndef MOVE_H
#define MOVE_H

#include <QObject>
#include "board/square.h"

class Move : public QObject
{
    Q_OBJECT
public:
    Move();
    Q_INVOKABLE virtual QList<QList<int>> getPossibleMoves(Piece * piece, QList<QList<Square *>> board);

signals:

};

#endif // MOVE_H
