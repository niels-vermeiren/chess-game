#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}

QList<QList<int>> BoardViewModel::clickedOnPiece(int row, int col) {
    QList<QList<Square *>> squaresPiece = this->squares();
    Piece * piece = this->squares()[row][col]->getPieceOnSquare();
    Move * move = MoveFactory::createMoveStrategy(piece, squaresPiece);
    QList<QList<int>> posMoves = move->getPossibleMoves();

    //Check if move does not result in a check, if so remove possible move
    int i = 0;
    while(i != posMoves.count()) {
        //Make move and check for check
        if(posMoves[i].count() > 0) {
            //Copy piece
            Piece * pieceClone = this->squares()[row][col]->getPieceOnSquare()->clone();
            int posRow = posMoves[i][0];
            int posCol = posMoves[i][1];

            this->squares()[row][col]->changePiece("","");
            Piece * capturedPiece = this->squares()[posRow][posCol]->getPieceOnSquare()->clone();
            this->squares()[posRow][posCol]->changePiece(pieceClone->pieceType(), pieceClone->pieceColour());

            bool isCheck = isCheckForColour(pieceClone->pieceColour());

            //Revert move
            this->squares()[row][col]->changePiece(pieceClone->pieceType(), pieceClone->pieceColour());
            this->squares()[posRow][posCol]->changePiece(capturedPiece->pieceType(), capturedPiece->pieceColour());

            if (!isCheck) i++;
            else posMoves.remove(i);
        }
    }


    return posMoves;
}

void BoardViewModel::newGame() {
    this->setSquares(BoardFactory::createBoard());
}

void BoardViewModel::setSquares(QList<QList<Square *>> squares) {
    this->m_squares = squares;
    emit squaresChanged();
}

bool BoardViewModel::isCheckForColour(QString colour) {
    bool res = GameRules::isCheckForColour(this->squares(), colour);
    if (colour == "black") emit checkForBlackChanged();
    else emit checkForWhiteChanged();
    return res;
}

bool BoardViewModel::isCheckMateForColour(QString colour) {
    bool res = GameRules::isCheckMateForColour(this->squares(), colour);
    if (colour == "black") emit checkMateForBlackChanged();
    else emit checkMateForWhiteChanged();
    return res;
}
