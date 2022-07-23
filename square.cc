#include "square.h"
#include <iostream>
using namespace std;

Square::Square(int bi, string name, bool prop) : boardIndex{bi}, name{name}, property{prop} {}

int Square::getBoardIndex() {
    return boardIndex;
}

int Square::getBoardIndex() {
    return boardIndex;
}

bool Square::isProperty() {
    return property;
}

std::string Square::getName() {
    return name;
}