#ifndef QUEEN_H
#define QUEEN_H
#include "pieces/piece.h"

class Queen : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)
    public:
        Queen(PieceColour colour);
        virtual ~Queen();
        QString pieceType() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // QUEEN_H