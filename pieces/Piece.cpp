#include "pieces/Piece.h"



Piece::Piece(Piece::PieceColour colour)
{
    this->colour = colour;
}

QString Piece::pieceType() const {

    return this->getPieceType();
};


QString Piece::getColour() {
    switch(this->colour) {
        case WHITE: return QString("white");
        case BLACK: return QString("black");
        case NONE: return QString("");
        default: return QString("");
    }
}

QString Piece::getPieceType() const {
    return QString("");
}

Piece::~Piece(){}
