#include "twowaybindinglistsquare.h"

TwoWayBindingListSquare::TwoWayBindingListSquare()
{
    QVector<Square*> squaresRow;
    Piece * piece = new Rook(Piece::PieceColour::BLACK);
    Square * square = new Square(Square::SquareColour::BLACK, piece);
    squaresRow.append(square);
    this->m_squares = squaresRow;

}

qsizetype TwoWayBindingListSquare::squareCount() const {
    return 8;
}

QQmlListProperty<Square> TwoWayBindingListSquare::squares() {
    return {this, this, &TwoWayBindingListSquare::squareCount, &TwoWayBindingListSquare::square};

}

Square * TwoWayBindingListSquare::square(qsizetype i) const {
    return this->m_squares.at(i);
}
