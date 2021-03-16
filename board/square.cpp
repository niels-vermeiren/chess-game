#include "square.h"

Square::Square(){}

Square::Square(SquareColour colour, Piece *piece) {
    this->colour = colour;
    this->m_piece = piece;
}

QString Square::squareColour() const {
    switch(this->colour) {
        case WHITE: return QString("#076a91");
        case BLACK: return QString("#ad9a4c");
        default: return QString("");
    }
}

void Square::setPieceOnSquare(Piece * piece){
    if (*this->m_piece != *piece) {
        delete this->m_piece;
        this->m_piece = piece;
        emit squarePieceChanged();
    }
}

Piece * Square::getPieceOnSquare() const {
    return this->m_piece;
}

void Square::changePiece(QString pieceType, QString pieceColour) {

    Piece::PieceColour colour = pieceColour == "white"? Piece::PieceColour::WHITE : Piece::PieceColour::BLACK;

    Piece * piece;

    if(pieceType == "♝") piece = new Bishop(colour);
    else if(pieceType == "♚") piece = new King(colour);
    else if(pieceType == "♞") piece = new Knight(colour);
    else if(pieceType == "♟") piece = new Pawn(colour);
    else if(pieceType == "♛") piece = new Queen(colour);
    else if(pieceType == "♜") piece = new Rook(colour);
    else piece = new Piece(colour);

    this->setPieceOnSquare(piece);
}

Square::~Square() {
    delete m_piece;
}


