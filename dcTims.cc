#include "dcTims.h"

DCTims::DCTims(string name, int bi) : Square(bi, name, false) {}

bool DCTims::useCup(Player& p) {
    int timsCup = p.getCups();
    if (timsCup > 0) {
        p.setCups(timsCup - 1);
        return true;
    }
    return false;
}


void DCTims::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;    
    s.boardIndex = this->getBoardIndex();
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
    s.boardIndex = this->getBoardIndex();
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();
}

void DCTims::newRound(Player& p) {
    int round = p.getJailRounds() + 1;
    p.setJailRounds(round);
}

void DCTims::sendOut(Player& p) {
    p.setJail(false);
    p.setJailRounds(0);
}

int DCTims::getCups(){
    return totalCups;
}

void DCTims::addCups() {
    totalCups++;
}

void DCTims::setCups(unsigned int n) {
    if (n <= 4) {
        totalCups = n;
    } else {
        totalCups = 4;
    }
}

