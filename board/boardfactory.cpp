#include "board/boardfactory.h"

const std::string initial[8][8] = {
        {"r", "k", "b", "K", "Q", "b", "k", "r"},
        {"p", "p", "p", "p", "p", "p", "p", ""},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {"p", "p", "p", "p", "p", "p", "p", ""},
        {"r", "", "", "K", "", "", "", "r"}
};

QList<QList<Square *>> BoardFactory::createBoard() {

    QList<QList<Square *>> squares;

    for(int x = 0 ; x != sizeof(initial)/sizeof(initial[0]) ; x++) {

        QList<Square *> squaresRow;
        squaresRow.clear();

        for(int y =0 ; y != sizeof(initial[0])/sizeof(initial[0][0]) ; y++) {

            Square::SquareColour squareColour = (x + y) % 2 == 0 ? Square::SquareColour::WHITE : Square::SquareColour::BLACK;
            Piece::PieceColour pieceColour = x == 0 || x == 1 ? Piece::PieceColour::BLACK :
                          x == 6 || x == 7 ? Piece::PieceColour::WHITE : Piece::PieceColour::NONE;

            Piece * piece = new Piece(pieceColour, x, y);

            if (initial[x][y] == "r") piece = new Rook(pieceColour, x, y);
            if (initial[x][y] == "k") piece = new Knight(pieceColour, x, y);
            if (initial[x][y] == "b") piece = new Bishop(pieceColour, x, y);
            if (initial[x][y] == "K") piece = new King(pieceColour, x, y);
            if (initial[x][y] == "Q") piece = new Queen(pieceColour, x, y);
            if (initial[x][y] == "p") piece = new Pawn(pieceColour, x, y);

            squaresRow.append(new Square(squareColour, piece, x, y));
        }
        squares.append(squaresRow);
    }
    return squares;
}
