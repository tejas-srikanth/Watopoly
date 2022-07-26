#include "property.h"
#include "player.h"
#include "state.h"
#include "academic.h"
class Player;

Property::Property(int bi, int pc, std::string name, bool a) : Square{bi, name, true}, purchaseCost{pc} {}

Player *Property::getOwner() {
    return owner;
}
Block *Property::getBlock() {
    return block;
}

int Property::getPurchaseCost() {
    return purchaseCost;
}

bool Property::getMortgaged() {
    return mortgaged;
}

void Property::setMortgage(bool m){
    mortgaged = m;
}

void Property::setOwner(Player *p) {
    int bi = this->getBoardIndex();
    if (!owner) {
        owner->delAssets(bi);
        owner->delAssets(this);
    }    
    owner = p;
    owner->addAssets(bi);
    owner->addAssets(this);
    struct State s;
    s.notifType = StateType::ChangeOwner;
    s.owner = owner;
    s.boardIndex = bi;
    this->setState(s);
    this->notifyObservers();
}

void Property::mortgage(Player *p) {
    mortgaged = true;
    p->changeBal(this->getPurchaseCost() / 2);
    struct State s;
    s.notifType = StateType::Mortgage;
    this->setState(s);
    this->notifyObservers();
}

void Property::unmortgage(Player *p) {
    mortgaged = false;
    p->changeBal(this->getPurchaseCost() * (-0.6));
    struct State s;
    s.notifType = StateType::Unmortgage;
    this->setState(s);
    this->notifyObservers();
} 

void Property::setBlock(Block* b){
    block = b;
}

bool Property::isAcad() {
    return acad;
}