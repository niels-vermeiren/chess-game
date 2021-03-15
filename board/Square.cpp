#include "Square.h"

Square::Square(){}

Square::Square(SquareColour colour, Piece *piece)
{
    this->colour = colour;
    this->piece = piece;
    this->m_piece = piece;
    this->m_squareColour = getColour();
}

Piece & Square::getPiece() {
    return * this->piece;
}

QString Square::getColour() const {
    switch(this->colour) {
        case WHITE: return QString("#076a91");
        case BLACK: return QString("#ad9a4c");
        default: return QString("");
    }
}

QString Square::squareColour() const {
    return this->getColour();
}

void Square::setSquareColour(QString squareColour) {
    if(this->m_squareColour != squareColour) {
        this->m_squareColour = squareColour;
        emit squareColourChanged();
    }
}

void Square::setPieceOnSquare(Piece * piece){
    if (piece->getColour() != this->m_piece->getColour() || piece->getPieceType() != this->m_piece->getPieceType()) {
        this->m_piece = piece;
        emit squarePieceChanged();
    }
}

void Square::setPiece(Piece &piece) {
    this->piece = &piece;
}

Piece * Square::getPieceOnSquare() const {
    return this->m_piece;
}

void Square::setPiez(QString pieceType, QString pieceColour) {

    Piece::PieceColour colour = pieceColour == "white"? Piece::PieceColour::WHITE : Piece::PieceColour::BLACK;

    Piece * piece = new Piece(colour);
    if(pieceType == "♝") piece = new Bishop(colour);
    if(pieceType == "♚") piece = new King(colour);
    if(pieceType == "♞") piece = new Knight(colour);
    if(pieceType == "♟") piece = new Pawn(colour);
    if(pieceType == "♛") piece = new Queen(colour);
    if(pieceType == "♜") piece = new Rook(colour);


    this->setPieceOnSquare(piece);
}

Square::~Square()
{
    delete piece;
}


