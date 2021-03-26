#include "computer.h"

Computer::Computer(QList<QList<Square *>> board) {
    this->board = board;
}

Q_INVOKABLE void Computer::makeMove() {
    QHash<Piece *, QList<int>> randomMove = getBestMove();
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
    QHash<Piece *, QList<int>> bestMove;
    QHash<Piece *, QList<QList<int>>> moves;
    //Get all pieces with at least one move
    for(int i=0; i != this->board.count(); i ++) {
        for(int j=0; j != this->board[0].count(); j++) {
            Piece * piece = this->board[i][j]->getPieceOnSquare()->clone();
            if (piece->pieceColour() != "black") continue;
            QList<QList<int>> possibleMoves = Game::getPossibleMoves(this->board, piece->getRow(), piece->getCol());
            if (possibleMoves.count() > 0) {
                //Insert move
                moves.insert(piece, possibleMoves);
            }
        }
    }
    int highestScore = -9999;
    //Make move, calculate score, reverse, keep track of highest
    for(int i = 0; i != moves.count(); i++) {
        Piece * piece = moves.keys().at(i)->clone();
        QList<QList<int>> possibleMoves = moves.values().at(i);
        for (int j = 0; j != possibleMoves.count(); j++) {
            //If it is a castling move
            if(Game::isCastlingMove(piece, possibleMoves[j])) {
                piece = Game::castle(board, piece, possibleMoves[j]);
                int score = BoardEvaluator::evaluateBoard(board);
                if (highestScore < score) {
                    highestScore = score;
                    bestMove.clear();
                    bestMove.insert(piece, possibleMoves[j]);
                }
                Game::reverseCastle(board, piece);
            } else {
                //Move
                Piece * capturedPiece = Game::makeMove(board, piece, possibleMoves[j]);
                int score = BoardEvaluator::evaluateBoard(board);
                if (highestScore < score) {
                    highestScore = score;
                    bestMove.clear();
                    bestMove.insert(piece, possibleMoves[j]);
                }
                //Revert move
                Game::undoMove(board, piece, capturedPiece, piece->getRow(), piece->getCol());
            }
        }
    }
    return bestMove;
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
