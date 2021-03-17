#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H
#include <memory>
#include "board/square.h"
#include <string>
#include "pieces/piece.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/pawn.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/king.h"

class BoardFactory {
    public:
        static QList<QList<Square *>> createBoard();
};
#endif // BOARDFACTORY_H
