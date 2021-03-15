#include "chessviewmodel.h"

ChessViewModel::ChessViewModel(QObject *parent) : QObject(parent)
{
}

void ChessViewModel::setBoard(Board & board) {
    this->board = &board;
}

QString ChessViewModel::getPieceAt(const int row, const int column) const
{
    return this->board->squares().at(row).at(column)->getPiece().getPieceType();
}

QString ChessViewModel::getPieceColourAt(const int row, const int column) const
{
    return this->board->squares().at(row).at(column)->getPiece().getColour();
}

QString ChessViewModel::getSquareColourAt(const int row, const int column) const {
    return this->board->squares().at(row).at(column)->getColour();
}

void ChessViewModel::movePiece() {
    std::shared_ptr<Square> from = this->board->squares().at(6).at(4);
    Piece * pieceToMove = &from->getPiece();
    Piece replacement(Piece::PieceColour::NONE);
    from->setPiece(replacement);
    std::shared_ptr<Square> to = this->board->squares().at(4).at(4);
    to->setPiece(*pieceToMove);
    this->board->squares()[6].replace(4, from);
    this->board->squares()[4].replace(4, to);
}


Square & ChessViewModel::getSquareAt(const int row, const int column)  {
    return *  this->board->squares()[row][column];
}
