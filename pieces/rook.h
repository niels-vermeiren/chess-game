#ifndef ROOK_H
#define ROOK_H
#include "pieces/piece.h"

class Rook : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ piece WRITE setPiece NOTIFY pieceChanged)
    public:
        Rook(PieceColour colour);
        virtual ~Rook();
        QString piece() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;

    protected:
        QString pieceType() const;
};

#endif // ROOK_H
