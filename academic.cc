#include "academic.h"
#include "subject.h"
#include "state.h"
#include "player.h"
#include "property.h"

Academic::Academic(int boardIndex, int purchaseCost, int ic, std::vector<int>imp, std::string name) :
    Property{boardIndex, purchaseCost, name}, improvementCost{ic}, improvements{imp} {}

int Academic::getImprovement() {
    return improvement;
}

int Academic::getImprovementCost() {
    return improvementCost;
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
    // notify Observers
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

void Academic::setImprovement(int imp){
    improvement = imp;
}

void Academic::buyImprovements() {
    improvement++;
    this->getOwner()->changeBal(improvementCost*(-1));
    struct State s;
    s.notifType = StateType::BuyImprovements;
    this->setState(s);
    this->notifyObservers();
}
void Academic::sellImprovements() {
    improvement--;
    this->getOwner()->changeBal(improvementCost/2);
    struct State s;
    s.notifType = StateType::SellImprovements;
    this->setState(s);
    this->notifyObservers();
}