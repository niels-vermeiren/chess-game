#ifndef KNIGHT_H
#define KNIGHT_H
#include "pieces/piece.h"

class Knight : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)

    public:
        Knight(PieceColour colour, int row, int col);
        virtual ~Knight();
        Piece * clone();
        QString pieceType() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // KNIGHT_H
