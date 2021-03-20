#ifndef GAMERULES_H
#define GAMERULES_H

#include <QObject>
#include <QList>
#include "board/square.h"
#include "moves/movefactory.h"

class GameRules : public QObject
{
    Q_OBJECT
public:
    GameRules();
    static bool isCheckForBlack(QList<QList<Square *>> board);
    static bool isCheckMateForBlack(QList<QList<Square *>> board);

signals:

};

#endif // GAMERULES_H
