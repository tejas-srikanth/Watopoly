#include "gym.h"
#include "subject.h"
#include "state.h"
#include "player.h"
#include <iostream>
using namespace std;

Gym::Gym( std::string name, int boardIndex, int purchaseCost) : Property{boardIndex, purchaseCost, name} {}

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
    int d1 = rand() % 6 + 1;     // d1 in the range 1 to 6
    int d2 = rand() % 6 + 1;
    cout << "You rolled a " << d1 << " and a " << d2 << endl;
    int cost = d1 + d2;
    if (numOfBuildings == 1) {
        cost *= 4;
    } else {
        cost *= 10;
    }
    p.changeBal(cost);
}