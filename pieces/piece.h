#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString pieceColour READ pieceColour NOTIFY pieceColourChanged)

    public:
        enum PieceColour {NONE, WHITE, BLACK};

        Piece(PieceColour colour, int row, int col);
        QString pieceColour();
        int getRow() const;
        int getCol() const;
        bool hasMoved() const;
        void setMoved(bool hasMoved);
        void pieceMoved();
        virtual QString pieceType() const;
        virtual Piece * clone();
        virtual int getScore();
        virtual ~Piece();

        bool operator!=(Piece &pc);

    protected:
        bool moved;
        PieceColour colour;
        int row;
        int col;

    signals:
        void pieceColourChanged();
};

#endif // PIECE_H
