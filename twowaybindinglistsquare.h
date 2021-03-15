#ifndef TWOWAYBINDINGLISTSQUARE_H
#define TWOWAYBINDINGLISTSQUARE_H

#include <QQmlListProperty>
#include <QObject>
#include <QtQml>
#include <board/Square.h>

class TwoWayBindingListSquare : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Square *> squares READ getSquares NOTIFY squaresChanged)


public:
    TwoWayBindingListSquare();
    QList<Square*> getSquares () const { return m_things; }

signals:
    void squaresChanged ();

private:
    QList<Square*> m_things;
    QVector<Square*> m_squares;
};

#endif // TWOWAYBINDINGLISTSQUARE_H
