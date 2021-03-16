#include "board/boardfactory.h"
#include <string>
#include "board/square.h"
#include "pieces/piece.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/king.h"

const std::string initial[8][8] = {
        {"r", "k", "b", "K", "Q", "b", "k", "r"},
        {"p", "p", "p", "p", "p", "p", "p", "p"},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", ".", ".", "."},
        {"p", "p", "p", "p", "p", "p", "p", "p"},
        {"r", "k", "b", "K", "Q", "b", "k", "r"}
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

            Piece * piece = new Piece(pieceColour);

            if (initial[x][y] == "r") piece = new Rook(pieceColour);
            if (initial[x][y] == "k") piece = new Knight(pieceColour);
            if (initial[x][y] == "b") piece = new Bishop(pieceColour);
            if (initial[x][y] == "K") piece = new King(pieceColour);
            if (initial[x][y] == "Q") piece = new Queen(pieceColour);
            if (initial[x][y] == "p") piece = new Pawn(pieceColour);

            squaresRow.append(new Square(squareColour, piece));
        }
        squares.append(squaresRow);
    }
    return squares;
}