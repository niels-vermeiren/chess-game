#include "twowaybindingsquare.h"

TwoWayBindingSquare::TwoWayBindingSquare()
{
    Piece * newPiece = new King(Piece::PieceColour::BLACK);

    Square * value = new Square(Square::SquareColour::WHITE, newPiece);
    this->m_value = value;


}

Square * TwoWayBindingSquare::getSquare() const
{
    return this->m_value;
}

void TwoWayBindingSquare::setSquare(Square * square)
{

    Piece * newPiece = new Rook(Piece::PieceColour::BLACK);

    Square * value =  new Square (Square::SquareColour::BLACK, newPiece);

    if ( this->m_value->getColour() != value->getColour() || this->m_value->getPiece().getPieceType() != value->getPiece().getPieceType() )
    {
        this->m_value = value;
        emit squareChanged();
    }

    // Comment out the above and uncomment out the below to get the binding loop error
//    m_value = value;
//    emit valueChanged();
}
