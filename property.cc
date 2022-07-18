#include "property.h"
#include "player.h"
#include "state.h"
class Player;

Property::Property(int bi, int pc) : Square{bi}, purchaseCost{pc} {}

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
    this->notifyObservers();
}

void Property::mortgage(Player &p) {
    mortgaged = true;
    p.changeBal(this->getPurchaseCost() / 2);
}

void Property::mortgage(Player &p) {
    mortgaged = false;
    p.changeBal(this->getPurchaseCost() * (-0.6));
} 