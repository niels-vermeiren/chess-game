#ifndef BOARD_H
#define BOARD_H
#include "board/Square.h"

class Board : public QObject
{
    Q_OBJECT

public:
    Board();
    Q_INVOKABLE QVector<QVector<std::shared_ptr<Square>>> & squares();
    void setSquares(QVector<QVector<std::shared_ptr<Square>>> & squares);
    virtual ~Board(){}
private:
    QVector<QVector<std::shared_ptr<Square>>> m_squares;
signals:

};

#endif // BOARD_H
