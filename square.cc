#include "square.h"

Square::Square(int bi) : boardIndex{bi} {}

int Square::getBoardIndex() {
    return boardIndex;
}