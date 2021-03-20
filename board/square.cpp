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

    Piece::PieceColour colour = pieceColour == "white" ? Piece::PieceColour::WHITE :
                                pieceColour == "black" ? Piece::PieceColour::BLACK : Piece::PieceColour::NONE;

    int row = this->m_piece->getRow();
    int col = this->m_piece->getCol();

    Piece * piece;

    if(pieceType == "♝") piece = new Bishop(colour, row, col);
    else if(pieceType == "♚") piece = new King(colour, row, col);
    else if(pieceType == "♞") piece = new Knight(colour, row, col);
    else if(pieceType == "♟") piece = new Pawn(colour, row, col);
    else if(pieceType == "♛") piece = new Queen(colour, row, col);
    else if(pieceType == "♜") piece = new Rook(colour, row, col);
    else piece = new Piece(colour, row, col);

    this->setPieceOnSquare(piece);

}

Square::~Square() {
    delete m_piece;
}


