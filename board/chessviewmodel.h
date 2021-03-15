#ifndef CHESSVIEWMODEL_H
#define CHESSVIEWMODEL_H
#include <vector>
#include "board.h"
#include "board/Square.h"
#include "board/BoardFactory.h"
#include <string.h>

class ChessViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString board NOTIFY boardChanged)
private:
    Board * board;

public:
    explicit ChessViewModel(QObject * parent = nullptr);
    void setBoard (Board & board);
    Q_INVOKABLE Square & getSquareAt(const int row, const int column) ;
    Q_INVOKABLE QString getPieceAt(const int row, const int column)  const;
    Q_INVOKABLE QString getPieceColourAt(const int row, const int column) const;
    Q_INVOKABLE QString getSquareColourAt(const int row, const int column) const;
    Q_INVOKABLE void movePiece();
    virtual ~ChessViewModel() {
        delete board;
    }

signals:
    void boardChanged();
};

#endif // CHESSVIEWMODEL_H
