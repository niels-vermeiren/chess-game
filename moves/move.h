#ifndef MOVE_H
#define MOVE_H

#include <QObject>

class Move : public QObject
{
    Q_OBJECT
public:
    explicit Move(QObject *parent = nullptr);

signals:

};

#endif // MOVE_H
