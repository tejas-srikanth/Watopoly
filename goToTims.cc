#include "goToTims.h"

GoToTims::GoToTims(string name, int bi, DCTims& tims) : Square{bi, name, false}, tims(tims) {}

void GoToTims::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.boardIndex = this->getBoardIndex();
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();

    tims.goToJail(p);
}
