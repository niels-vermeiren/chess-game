#include "Main.h"
#include "pieces/Rook.h"
#include <iostream>

Main::Main() {}

Main::~Main() {}

int main() {
    Rook rook(PieceColour::BLACK);
    if (rook.getColour() == PieceColour::BLACK) {
        std::cout << "Piece has black colour: " << "/n";
    }
    if (rook.pieceType == PieceType::Rook) {
        std::cout << "Piece is a rook" << "/n";
    }
    return 0;
}
