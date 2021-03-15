#ifndef PAWN_H
#define PAWN_H
#include "pieces/piece.h"

class Pawn: public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ piece WRITE setPiece NOTIFY pieceChanged)
    public:
        Pawn(PieceColour colour);
        virtual ~Pawn();
        QString pieceType() const;
        QString piece() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // PAWN_H
