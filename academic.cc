#include "academic.h"
#include "subject.h"
#include "state.h"
#include "player.h"
#include "property.h"

Academic::Academic(int boardIndex, int purchaseCost) : Property{boardIndex, purchaseCost} {}

void Academic::land(Player &p) {
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.owner = this->getOwner();
    s.property = PropertyType::Academic;
    this->setState(s);
    this->notifyObservers();
    payFee(p);
}
void Academic::payFee(Player &p) {
    if (&p != this->getOwner()) {
        int cost = improvements[improvement] * (-1);
        if (improvement == 0) {
            p.changeBal(cost * this->getState().condition);
        } else {
            p.changeBal(cost);
        }
    }
    
    
}