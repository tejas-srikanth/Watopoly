#include "residence.h"
#include "subject.h"
#include "state.h"
#include "player.h"
#include <iostream>
using namespace std;

Residence::Residence(std::string name, int boardIndex) : Property{boardIndex, 200, name} {
    costs.insert(pair<int, int>(1, 25));
    costs.insert(pair<int, int>(2, 50));
    costs.insert(pair<int, int>(3, 100));
    costs.insert(pair<int, int>(4, 200));
}

void Residence::land(Player &p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.owner = this->getOwner();
    s.property = PropertyType::Residence;
    this->setState(s);
    this->notifyObservers();
    if (!this->getMortgaged()) {
        payFee(p);
    }    
}
void Residence::payFee(Player &p) {
    int numOfBuildings = this->getState().condition;
    int cost = costs[numOfBuildings] * (-1);
    p.changeBal(cost);
}


