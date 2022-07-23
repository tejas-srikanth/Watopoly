#include "academic.h"
#include "subject.h"
#include "state.h"
#include "player.h"
#include "property.h"

Academic::Academic(int boardIndex, int purchaseCost, std::map<int,int>imp) :
    Property{boardIndex, purchaseCost}, improvements{imp} {}

int Academic::getImprovement() {
    return improvement;
}

void Academic::land(Player &p) {
    p.changePos(this->getBoardIndex());
    // setting State s
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
    int cost = improvements[improvement] * (-1);
    if (improvement == 0) {
        int bal = cost * this->getState().condition;
        p.changeBal(bal);
        this->getOwner()->changeBal(bal * (-1));
    } else {
        p.changeBal(cost);
        this->getOwner()->changeBal(cost * (-1));
    }
}

void Academic::buyImprovements() {
    improvement++;
    this->getOwner()->changeBal(improvements[improvement]*(-1));
    struct State s;
    s.notifType = StateType::BuyImprovements;
    this->setState(s);
    this->notifyObservers();
}
void Academic::sellImprovements() {
    improvement--;
    this->getOwner()->changeBal(improvements[improvement]/2);
    struct State s;
    s.notifType = StateType::SellImprovements;
    this->setState(s);
    this->notifyObservers();
}