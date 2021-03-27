#include "computer.h"

Computer::Computer(QList<QList<Square *>> board) {
    this->board = board;
    this->minimax = new Minimax(this->board);
}

Computer::~Computer() {
    delete this->minimax;
}

Q_INVOKABLE void Computer::makeMove() {
    QHash<Piece *, QList<int>> move = this->minimax->minimaxRoot(Game::DEPTH);
    //Move piece
    if (move.count() > 0) {
        Piece * piece = move.keys()[0]->clone();
        QList<int> possibleMove = move.values()[0];
        this->board[piece->getRow()][piece->getCol()]->changePiece("", "", false);
        this->board[possibleMove[0]][possibleMove[1]]->changePiece(piece->pieceType(), piece->pieceColour(), true);
        replacePawnWithPiece(piece, possibleMove);
    }
}

void Computer::replacePawnWithPiece(Piece * piece, QList<int> move) {
    //If pawn has reached the end
    if(piece->pieceType() == "♟" && move[0] == 7) {
        this->board[move[0]][move[1]]->changePiece("♛", piece->pieceColour(), true);
    }
}

