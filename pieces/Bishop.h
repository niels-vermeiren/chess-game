#ifndef BISHOP_H
#define BISHOP_H
#include "pieces/Piece.h"

class Bishop : public Piece
{
    public:
        Bishop(PieceColour pieceColour);
        QString getPieceType();
        virtual ~Bishop();
};

#endif // BISHOP_H
