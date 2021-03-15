#include "pieces/piece.h"



Piece::Piece(Piece::PieceColour colour)
{
    this->colour = colour;
}

QString Piece::pieceType() const {
    return "";
};


QString Piece::pieceColour() {
    switch(this->colour) {
        case WHITE: return QString("white");
        case BLACK: return QString("black");
        case NONE: return QString("");
        default: return QString("");
    }
}

Piece::~Piece(){}
