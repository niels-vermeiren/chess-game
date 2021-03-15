#ifndef KNIGHT_H
#define KNIGHT_H
#include "pieces/Piece.h"

class Knight : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ piece WRITE setPiece NOTIFY pieceChanged)
    public:
        Knight(PieceColour colour);
        virtual ~Knight();
        QString getPieceType() const;
        QString piece() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // KNIGHT_H
