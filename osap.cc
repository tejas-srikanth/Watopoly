#include "osap.h"

Osap::Osap(std::string name, int index) : Square(index, name, false) {}

void Osap::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    //p.changeBal(200);
}
