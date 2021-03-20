#ifndef KING_H
#define KING_H
#include "pieces/piece.h"

class King : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)
    public:
        King(PieceColour colour, int row, int col);
        virtual ~King();
        Piece * clone();
        QString pieceType() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // KING_H
