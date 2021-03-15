#ifndef KNIGHT_H
#define KNIGHT_H
#include "pieces/Piece.h"

class Knight : public Piece
{
    public:
        Knight(PieceColour colour);
        QString getPieceType();
        virtual ~Knight();
};

#endif // KNIGHT_H
