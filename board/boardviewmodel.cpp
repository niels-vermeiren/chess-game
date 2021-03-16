#include "boardviewmodel.h"

BoardViewModel::BoardViewModel(){
    this->m_squares = BoardFactory::createBoard();
}

QList<QList<Square*>> BoardViewModel::squares () const {
    return this->m_squares;
}
