#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString pieceColour READ pieceColour NOTIFY pieceColourChanged)
    public:
        enum PieceColour {NONE, WHITE, BLACK};

        Piece(PieceColour colour, int row, int col);

        QString pieceColour();
        int getRow() const;
        int getCol() const;
        virtual QString pieceType() const;
        virtual Piece * clone();
        virtual ~Piece();

        bool operator!=(Piece &pc);

    protected:
        PieceColour colour;
        int row;
        int col;

    signals:
        void pieceColourChanged();
};

#endif // PIECE_H
