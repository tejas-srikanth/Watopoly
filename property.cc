#include "property.h"
#include "player.h"
#include "state.h"
class Player;

Property::Property(int bi, int pc, std::string name) : Square{bi, name, true}, purchaseCost{pc} {}

Player *Property::getOwner() {
    return owner;
}
Block *Property::getBlock() {
    return block;
}

int Property::getPurchaseCost() {
    return purchaseCost;
}

void Property::setOwner(Player *p) {
    int bi = this->getBoardIndex();
    owner->delAssets(bi);
    owner = p;
    p->addAssets(bi);
    struct State s;
    s.notifType = StateType::ChangeOwner;
    s.owner = owner;
    s.boardIndex = bi;
    this->setState(s);
    this->notifyObservers();
}

void Property::mortgage(Player &p) {
    mortgaged = true;
    p.changeBal(this->getPurchaseCost() / 2);
    struct State s;
    s.notifType = StateType::Mortgage;
    this->setState(s);
    this->notifyObservers();
}

void Property::unmortgage(Player &p) {
    mortgaged = false;
    p.changeBal(this->getPurchaseCost() * (-0.6));
    struct State s;
    s.notifType = StateType::Unmortgage;
    this->setState(s);
    this->notifyObservers();
} 