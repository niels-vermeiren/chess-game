#ifndef TWOWAYBINDINGSQUARE_H
#define TWOWAYBINDINGSQUARE_H

#include <QObject>
#include <board/Square.h>
#include <pieces/Piece.h>
#include <pieces/Rook.h>
#include <pieces/King.h>

class TwoWayBindingSquare : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Square * square READ getSquare WRITE setSquare NOTIFY squareChanged)

public:
    TwoWayBindingSquare();
    Square * getSquare() const;

public slots:
    void setSquare(Square * square);


signals:
    void squareChanged();


private:
    Square * m_value;
};

#endif // TWOWAYBINDINGSQUARE_H
