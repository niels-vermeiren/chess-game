#ifndef PAWN_H
#define PAWN_H
#include "pieces/Piece.h"

class Pawn: public Piece
{
    public:
        Pawn(PieceColour colour);
        QString getPieceType();
        virtual ~Pawn();
};

#endif // PAWN_H
