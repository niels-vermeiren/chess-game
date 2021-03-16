#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString pieceColour READ pieceColour NOTIFY pieceColourChanged)
    public:
        enum PieceColour {NONE, WHITE, BLACK};

        Piece(PieceColour colour);
        QString pieceColour();
        virtual QString pieceType() const;
        virtual ~Piece();

        bool operator!=(Piece &pc);

    private:
        PieceColour colour;

    signals:
        void pieceColourChanged();
};

#endif // PIECE_H
