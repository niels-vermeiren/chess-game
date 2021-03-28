#include "positions.h"

Positions::Positions()
{
}

QList<int> Positions::blackKingPosition= {0,3};
QList<int> Positions::whiteKingPosition= {0,3};


QList<int> Positions::getBlackKingPosition() {
    return blackKingPosition;
}
void Positions::setBlackKingPosition(QList<int> position) {
    blackKingPosition = position;
}

QList<int> Positions::getWhiteKingPosition() {
    return whiteKingPosition;
}
void Positions::setWhiteKingPosition(QList<int> position) {
    whiteKingPosition = position;
}
