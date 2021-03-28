#ifndef POSITIONS_H
#define POSITIONS_H
#include <qlist.h>

class Positions
{
    static QList<int> blackKingPosition;
    static QList<int> whiteKingPosition;

    public:
        Positions();
        static QList<int> getBlackKingPosition();
        static void setBlackKingPosition(QList<int> position);
        static QList<int> getWhiteKingPosition();
        static void setWhiteKingPosition(QList<int> position) ;
};

#endif // POSITIONS_H
