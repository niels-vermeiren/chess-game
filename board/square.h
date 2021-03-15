#ifndef SQUARE_H
#define SQUARE_H
#include "pieces/piece.h"
#include <QObject>

#include "pieces/bishop.h"
#include "pieces/rook.h"
#include "pieces/king.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"

class Square : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString squareColour READ squareColour WRITE setSquareColour NOTIFY squareColourChanged)
    Q_PROPERTY(Piece * piece READ getPieceOnSquare WRITE setPieceOnSquare NOTIFY squarePieceChanged)
public:
    enum SquareColour { BLACK, WHITE };
    Square();
    Square(SquareColour colour, Piece * piece);
    Q_INVOKABLE Piece & getPiece();
    QString getColour() const;
    QString squareColour() const;
    void setPiece(Piece & piece);
    virtual ~Square();
    Piece * getPieceOnSquare() const;
    Q_INVOKABLE void setPiez(QString pieceType, QString pieceColour);

public slots:
    void setSquareColour(QString squareColour);
    void setPieceOnSquare(Piece *  piece);

signals:
    void squarePieceChanged();
    void squareColourChanged();

private:
    QString m_squareColour;
    SquareColour colour;
    Piece * piece;
    Piece * m_piece;
};

#endif // SQUARE_H
