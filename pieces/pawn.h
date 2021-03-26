#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn: public Piece {
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)

    public:
        Pawn(PieceColour colour, int row, int col);
        virtual ~Pawn();
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

#endif // PAWN_H
