#include "gooseNesting.h"

void GooseNesting::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.property = PropertyType::Special;
    this->setState(s);
    this->notifyObservers();
}
