#include "gym.h"
#include "subject.h"
#include "state.h"
#include "player.h"

void Gym::land(Player &p) {
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.owner = this->getOwner();
    s.property = PropertyType::Gym;
    this->setState(s);
    this->notifyObservers();
    payFee(p);
}
void Gym::payFee(Player &p) {
    if (&p != this->getOwner()) {
        int numOfBuildings = this->getState().condition;
        int cost;
        if (numOfBuildings == 1) {
            cost *= 4;
        } else {
            cost *= 10;
        }
        p.changeBal(cost);
    }
}