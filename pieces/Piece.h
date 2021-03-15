#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT
    public:
        enum PieceColour {NONE, WHITE, BLACK};
        Piece(PieceColour colour);
        QString pieceType() const;
        Q_INVOKABLE QString getColour();
        Q_INVOKABLE virtual QString getPieceType() const;
        virtual ~Piece();
    private:
        PieceColour colour;
};

#endif // PIECE_H
