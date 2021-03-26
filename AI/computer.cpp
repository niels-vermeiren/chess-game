#include "computer.h"

Computer::Computer(QList<QList<Square *>> board) {
    this->board = board;
}

Q_INVOKABLE void Computer::makeMove() {
    QHash<Piece *, QList<int>> randomMove = getRandomMove();
    //Move piece
    if (randomMove.count() > 0) {
        Piece * piece = randomMove.keys()[0]->clone();
        QList<int> possibleMove = randomMove.values()[0];
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

QHash<Piece *, QList<int>> Computer::getBestMove() {
    QHash<Piece *, QList<int>> result;
    return result;
}

QHash<Piece *, QList<int>> Computer::getRandomMove() {
    QHash<Piece *, QList<int>> result;
    QList<QHash<Piece *, QList<int>>> moves;
    //Get all pieces with at least one move
    for(int i=0; i != this->board.count(); i ++) {
        for(int j=0; j != this->board[0].count(); j++) {
            Piece * piece = this->board[i][j]->getPieceOnSquare()->clone();
            if (piece->pieceColour() != "black") continue;
            QList<QList<int>> possibleMoves = Game::getPossibleMoves(this->board, piece->getRow(), piece->getCol());
            if (possibleMoves.count() > 0) {
                //Insert random move
                QList<int> randomMove = possibleMoves[rand() % possibleMoves.count()];
                result.insert(piece, randomMove);
                moves.append(result);
            }
        }
    }
    //Return random move
    if (moves.count() == 0) return result;
    return moves.at(random() % moves.count());
}
