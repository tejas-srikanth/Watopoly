#include "coopFee.h"

void CoopFee::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    int balance = p.getBal();
    p.changeBal(balance - 150);
}
