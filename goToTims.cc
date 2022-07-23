#include "goToTims.h"

GoToTims::GoToTims(int bi, bool prop, Square& tims) : Square{bi, prop}, tims(tims) {}

void GoToTims::land(Player p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.property = PropertyType::Special;
    this->setState(s);

    tims.goToJail(Player p);
}