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
    static bool isCheckForColour(QList<QList<Square *>> board, QString colour);
    static bool isCheckMateForColour(QList<QList<Square *>> board, QString colour);

signals:

};

#endif // GAMERULES_H
