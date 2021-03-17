#ifndef POSSIBLEMOVE_H
#define POSSIBLEMOVE_H
#include <QObject>

class PossibleMove : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int row READ getRow)
    Q_PROPERTY(int col READ getCol)

    private:
        int row;
        int col;

    public:
        PossibleMove(int row, int col);
        int getRow() const;
        int getCol() const;
        virtual ~PossibleMove();
};

#endif // POSSIBLEMOVE_H
