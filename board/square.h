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
        Square(SquareColour colour, Piece * piece);
        virtual ~Square();
        QString squareColour() const;
        Piece * getPieceOnSquare() const;
        Q_INVOKABLE void changePiece(QString pieceType, QString pieceColour);

    public slots:
        void setPieceOnSquare(Piece *  piece);

    signals:
        void squarePieceChanged();
        void squareColourChanged();

    private:
        SquareColour colour;
        Piece * m_piece;
};

#endif // SQUARE_H
