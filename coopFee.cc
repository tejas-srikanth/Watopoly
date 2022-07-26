#include "coopFee.h"

CoopFee::CoopFee(std::string name, int index) : Square(index, name, false) {}

void CoopFee::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.boardIndex = this->getBoardIndex();
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    p.changeBal(-150);
}
