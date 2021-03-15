#include "boardviewmodel.h"

BoardViewModel::BoardViewModel()
{

    this->m_squares = BoardFactory::createBoard();

}
