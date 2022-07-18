#include "residence.h"
#include "subject.h"
#include "state.h"
#include "player.h"

void Residence::land(Player &p) {
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
    if (&p != this->getOwner()) {
        int numOfBuildings = this->getState().condition;
        int cost = costs[numOfBuildings] * (-1);
        p.changeBal(cost);
    }
}


