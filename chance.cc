#include "chance.h"

Chance::Chance(int bi, string name) : Square{bi, name, false} {}

int Chance::getTimsCup(Player& p) {
    return p.getCups();
}

bool Chance::useCup(Player& p) {
    int timsCup = this->getTimsCup(p);
    if (timsCup > 0) {
        p.setCups(timsCup - 1);
        return true;
    }
    return false;
}

void Chance::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.property = PropertyType::Special;
    this->setState(s);
    this->notifyObservers();

    if (totalCups < 4) {
        int random = rand() % 100;
        if (random == 99) {
            p.setCups(p.getCups() + 1);
            totalCups++;
        }
    }
    getEffect(p);
}
