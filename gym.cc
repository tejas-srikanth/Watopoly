#include "gym.h"
#include "subject.h"
#include "state.h"
#include "player.h"

Gym::Gym(int boardIndex, int purchaseCost) : Property{boardIndex, purchaseCost} {}

void Gym::land(Player &p) {
    p.changePos(this->getBoardIndex());
    // setting State s
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
    int numOfBuildings = this->getState().condition;
    int cost;
    if (numOfBuildings == 1) {
        cost *= 4;
    } else {
        cost *= 10;
    }
    p.changeBal(cost);
}