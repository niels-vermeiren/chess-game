#include "twowaybindinglistsquare.h"

TwoWayBindingListSquare::TwoWayBindingListSquare()
{
    QVector<Square*> squaresRow;
    Piece * piece = new Rook(Piece::PieceColour::BLACK);
    Square * square = new Square(Square::SquareColour::BLACK, piece);
    squaresRow.append(square);
    this->m_squares = squaresRow;
    QList<Square*> squarez = QList<Square*>::fromVector(this->m_squares);
    this->m_things = squarez;
}


