#include "square.h"

Square::Square(){}

Square::Square(SquareColour colour, Piece *piece, int row, int col) {
    this->colour = colour;
    this->m_piece = piece;
    this->row = row;
    this->col = col;
}

QString Square::squareColour() const {
    switch(this->colour) {
        case WHITE: return QString("#b5b262");
        case BLACK: return QString("#22751c");
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

void Square::changePiece(QString pieceType, QString pieceColour, bool hasBeenMoved) {

    Piece::PieceColour colour = pieceColour == "white" ? Piece::PieceColour::WHITE :
                                pieceColour == "black" ? Piece::PieceColour::BLACK : Piece::PieceColour::NONE;
    int row = this->getRow();
    int col = this->getCol();

    Piece * piece;

    if(pieceType == "♝") piece = new Bishop(colour, row, col);
    else if(pieceType == "♚") piece = new King(colour, row, col);
    else if(pieceType == "♞") piece = new Knight(colour, row, col);
    else if(pieceType == "♟") piece = new Pawn(colour, row, col);
    else if(pieceType == "♛") piece = new Queen(colour, row, col);
    else if(pieceType == "♜") piece = new Rook(colour, row, col);
    else piece = new Piece(colour, row, col);
    piece->setMoved(hasBeenMoved);
    this->setPieceOnSquare(piece);
}

int Square::getRow() const {
    return this->row;
}

int Square::getCol() const {
    return this->col;
}

Square::~Square() {
    delete m_piece;
}


