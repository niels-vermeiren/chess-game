#ifndef BISHOP_H
#define BISHOP_H
#include "pieces/piece.h"

class Bishop : public Piece {
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)

    public:
        Bishop(PieceColour colour, int row, int col);
        virtual ~Bishop();
        Piece * clone();
        QString pieceType() const;
        int getScore();

    public slots:
        void setPiece(QString piece);

    signals:
        void pieceChanged();

    private:
        QString m_piece;
};

#endif // BISHOP_H
