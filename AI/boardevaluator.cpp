#include "boardevaluator.h"

BoardEvaluator::BoardEvaluator() {}

int BoardEvaluator::evaluateBoard(QList<QList<Square *>> board) {
    int sum = 0;
    for(int i = 0; i != board.count(); i++) {
        for(int j = 0; j != board[0].count(); j++) {
            Piece * piece = board[i][j]->getPieceOnSquare();
            if (piece->pieceType() == "") continue;
            int points = piece->pieceColour() == "black" ? piece->getScore() : - piece->getScore();
            sum += points;
        }
    }
    return sum;
}
