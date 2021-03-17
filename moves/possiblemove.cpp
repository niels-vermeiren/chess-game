#include "possiblemove.h"

PossibleMove::PossibleMove(int row, int col){
    this->row = row;
    this->col = col;
}
int PossibleMove::getRow() const {
    return this->row;
}
int PossibleMove::getCol() const {
    return this->col;
}
PossibleMove::~PossibleMove() {}
