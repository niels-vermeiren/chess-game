#include "minimax.h"

Minimax::Minimax(QList<QList<Square *>> board) {
    this->board = board;
}

QHash<Piece *, QList<int>> Minimax::minimaxRoot(int depth) {
    QHash<Piece *, QList<QList<int>>> newGameMoves = this->getNextMoves("black");
    int bestMove = -9999;
    QHash<Piece *, QList<int>> bestNextMove;

    for (int i = 0; i < newGameMoves.count(); i++) {
        for (int j = 0; j < newGameMoves.values()[i].count(); j++) {
            Piece * pieceClone = newGameMoves.keys()[i];
            int row = pieceClone->getRow();
            int col = pieceClone->getCol();

            Piece * capturedPiece = Game::makeMove(board, pieceClone, newGameMoves.values()[i][j]);
            int value = minimax(depth -1, board, -100000, 100000, false);
            Game::undoMove(board, pieceClone, capturedPiece, row, col);

            if(value >= bestMove) {
                bestMove = value;
                bestNextMove.clear();
                bestNextMove.insert(pieceClone, newGameMoves.values()[i][j]);
            }

        }
    }

    return bestNextMove;
};

int Minimax::minimax(int depth, QList<QList<Square *>> board, int alpha, int beta, bool isMaximisingPlayer) {
    if (depth == 0) {
        return BoardEvaluator::evaluateBoard(board);
    }
    if (isMaximisingPlayer) {
        int bestMove = -9999;
        QHash<Piece *, QList<QList<int>>> newGameMoves = getNextMoves("black");
        for (int i = 0; i < newGameMoves.count(); i++) {
            for (int j = 0; j < newGameMoves.values()[i].count(); j++) {
                Piece * piece = newGameMoves.keys()[i];
                int row = piece->getRow();
                int col = piece->getCol();
                Piece * capturedPiece = Game::makeMove(board, piece, newGameMoves.values()[i][j]);
                bestMove = std::max(bestMove, minimax(depth - 1, board, alpha, beta, !isMaximisingPlayer));
                Game::undoMove(board, piece, capturedPiece, row, col);
                alpha = std::max(alpha, bestMove);
                if (alpha >= beta) {
                    return bestMove;
                }
            }
        }
        return bestMove;
    } else {
        int bestMove = 9999;
        QHash<Piece *, QList<QList<int>>> newGameMoves = getNextMoves("white");
        for (int i = 0; i < newGameMoves.count(); i++) {
            for (int j = 0; j < newGameMoves.values()[i].count(); j++) {
                Piece * piece = newGameMoves.keys()[i];
                int row = piece->getRow();
                int col = piece->getCol();
                Piece * capturedPiece = Game::makeMove(board, piece, newGameMoves.values()[i][j]);
                bestMove = std::min(bestMove, minimax(depth - 1, board, alpha, beta, !isMaximisingPlayer));
                Game::undoMove(board, piece, capturedPiece, row, col);
                beta = std::min(beta, bestMove);
                if (beta <= alpha) {
                    return bestMove;
                }
            }
        }
        return bestMove;
    }
}

QHash<Piece *, QList<QList<int>>> Minimax::getNextMoves(QString colour) {
    QHash<Piece *, QList<QList<int>>> moves;
    //Get all pieces with at least one move
    for(int i=0; i != this->board.count(); i ++) {
        for(int j=0; j != this->board[0].count(); j++) {
            Piece * piece = this->board[i][j]->getPieceOnSquare()->clone();
            if (piece->pieceColour() != colour) continue;
            QList<QList<int>> possibleMoves = Game::getPossibleMoves(this->board, piece->getRow(), piece->getCol());
            if (possibleMoves.count() > 0) {
                //Insert move
                moves.insert(piece, possibleMoves);
            }
        }
    }
    return moves;
}
