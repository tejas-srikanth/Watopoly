#include "dcTims.h"

void DCTims::land(Player p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.property = PropertyType::Special;
    this->setState(s);

    return;
}

void DCTims::goToJail(Player p) {
    roundChecker[p] = 0;
    p.changePos(this->getBoardIndex());
}

int DCTims::getRound(Player p) {
    round = roundChecker[p];
    return round;
}

void DCTims::newRound(Player p) {
    roundChecker[p]++;
}

void DCTims::sendOut(Player p) {
    roundChecker.erase(p);
}

int DCTims::getJailRounds(Player p) {
    return roundChecker[p];
}