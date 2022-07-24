#include "goToTims.h"

GoToTims::GoToTims(int bi, string name, bool prop, DCTims& tims) : Square{bi, name, prop}, tims(tims) {}

void GoToTims::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    tims.goToJail(p);
}
