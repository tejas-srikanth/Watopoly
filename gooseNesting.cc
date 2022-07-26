#include "gooseNesting.h"

GooseNesting::GooseNesting(std::string name, int index) : Square(index, name, false) {}

void GooseNesting::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.boardIndex = this->getBoardIndex();
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();
}
