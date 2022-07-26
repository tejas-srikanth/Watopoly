#include "square.h"
#include <iostream>
using namespace std;

Square::Square(int bi, string name, bool prop) : boardIndex{bi}, name{name}, property{prop} {}

int Square::getBoardIndex() {
    return boardIndex;
}

bool Square::isProperty() {
    return property;
}

std::string Square::getName() {
    return name;
}

void Square::bankrupt(Player *p) {
    struct State s;
    s.notifType = StateType::Bankrupt;
    s.justLanded = p;
    this->setState(s);
    this->notifyObservers();
}

Square::~Square() {}
