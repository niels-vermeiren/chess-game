#include "pieces/piece.h"

Piece::Piece(Piece::PieceColour colour, int row, int col) {
    this->colour = colour;
    this->row = row;
    this->col = col;
}

Piece * Piece::clone() {
    PieceColour colour = PieceColour::NONE;
    if(this->pieceColour() == "white") colour = PieceColour::WHITE;
    if(this->pieceColour() == "black") colour = PieceColour::BLACK;
    return new Piece(colour, this->getRow(), this->getCol());
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

int Piece::getRow() const {
    return this->row;
}

int Piece::getCol() const {
    return this->col;
}

Piece::~Piece(){

}
