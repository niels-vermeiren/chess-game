#ifndef ROOK_H
#define ROOK_H
#include "pieces/piece.h"

class Rook : public Piece {
    Q_OBJECT
    Q_PROPERTY(QString piece READ pieceType WRITE setPiece NOTIFY pieceChanged)

    public:
        Rook(PieceColour colour, int row, int col);
        virtual ~Rook();
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

#endif // ROOK_H
