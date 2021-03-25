#ifndef SQUARE_H
#define SQUARE_H
#include <QObject>
#include "pieces/piece.h"
#include "pieces/bishop.h"
#include "pieces/rook.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"

class Square : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString squareColour READ squareColour NOTIFY squareColourChanged)
    Q_PROPERTY(Piece * piece READ getPieceOnSquare WRITE setPieceOnSquare NOTIFY squarePieceChanged)

    public:
        enum SquareColour { BLACK, WHITE };
        Square();
        Square(SquareColour colour, Piece * piece, int row, int col);
        virtual ~Square();
        QString squareColour() const;
        Piece * getPieceOnSquare() const;
        Q_INVOKABLE void changePiece(QString pieceType, QString pieceColour, bool hasBeenMoved);
        int getRow() const;
        int getCol() const;

    public slots:
        void setPieceOnSquare(Piece *  piece);

    signals:
        void squarePieceChanged();
        void squareColourChanged();

    private:
        SquareColour colour;
        Piece * m_piece;
        int row;
        int col;
};

#endif // SQUARE_H
