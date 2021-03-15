#ifndef QUEEN_H
#define QUEEN_H
#include "pieces/Piece.h"

class Queen : public Piece
{
    public:
        Queen(PieceColour colour);
        virtual ~Queen();
        QString getPieceType();
};

#endif // QUEEN_H
