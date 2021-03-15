#ifndef TWOWAYBINDINGLISTSQUARE_H
#define TWOWAYBINDINGLISTSQUARE_H

#include <QQmlListProperty>
#include <QObject>
#include <QtQml>
#include <board/Square.h>

class TwoWayBindingListSquare : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Square> squares READ squares)
    QML_ELEMENT

public:
    TwoWayBindingListSquare();

    QQmlListProperty<Square> squares();
    qsizetype squareCount() const;
    Square *square(qsizetype) const;


private:
    static Square * square(QQmlListProperty<Square>*, qsizetype);
    static qsizetype squareCount(QQmlListProperty<Square>*);
    QVector<Square*> m_squares;
};

#endif // TWOWAYBINDINGLISTSQUARE_H
