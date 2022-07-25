#include "chance.h"

Chance::Chance(int bi, string name) : Square{bi, name, false} {}

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
