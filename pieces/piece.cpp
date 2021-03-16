#include "pieces/piece.h"

Piece::Piece(Piece::PieceColour colour) {
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

bool Piece::operator!=(Piece &pc) {
    return this->pieceColour() != pc.pieceColour() || this->pieceType() != pc.pieceType();
}


Piece::~Piece(){}
