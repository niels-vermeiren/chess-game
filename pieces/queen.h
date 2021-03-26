#ifndef QUEEN_H
#define QUEEN_H
#include "pieces/piece.h"

class Queen : public Piece {
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)

    public:
        Queen(PieceColour colour, int row, int col);
        virtual ~Queen();
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

#endif // QUEEN_H
