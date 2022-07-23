#include "chance.h"

int Chance::getTimsCup(Player p) {
    int timsCup = 0;
    for (int i = 0; i < totalCups; i++) {
        if (cups[i] == p) {
            timsCup++;
        }
    }
    return timsCup;
}

bool Chance::useCup(Player p) {
    for (int i = 0; i < totalCups; i++) {
        if (cups[i] == p) {
            cups.erase(cups.begin() + i);
            totalCups--;
            return true;
        }
    }
    return false;
}

void Chance::land(Player p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.owner = this->getOwner();
    s.property = PropertyType::Special;
    this->setState(s);

    if (totalCups < 4) {
        int random = rand() % 100;
        if (random == 99) {
            cups.push_back(p);
            totalCups++;
        }
    }
    getEffect();
}