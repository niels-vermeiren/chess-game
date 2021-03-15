    #ifndef SQUARE_H
#define SQUARE_H
#include "pieces/Piece.h"
#include <QObject>

#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"

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
