#ifndef BISHOP_H
#define BISHOP_H
#include "pieces/Piece.h"

class Bishop : public Piece
{
    Q_OBJECT
    Q_PROPERTY(QString piece READ piece WRITE setPiece NOTIFY pieceChanged)
    public:
        Bishop(PieceColour colour);
        virtual ~Bishop();
        QString getPieceType() const;
        QString piece() const;

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // BISHOP_H
