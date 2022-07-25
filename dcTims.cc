#include "dcTims.h"

DCTims::DCTims(string name, int bi) : Square(bi, name, true) {}

void DCTims::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    return;
}

void DCTims::goToJail(Player& p) {
    p.setJail(true);
    p.setJailRounds(0);
    p.changePos(this->getBoardIndex());

    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();
}

int DCTims::getRound(Player& p) {
    return p.getJailRounds();
}

void DCTims::newRound(Player& p) {
    int round = p.getJailRounds() + 1;
    p.setJailRounds(round);
}

void DCTims::sendOut(Player& p) {
    p.setJail(false);
    p.setJailRounds(0);
}
