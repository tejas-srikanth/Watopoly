#include "subject.h"
//#include "observer.h"
#include <vector>

void Subject::notifyObservers() {
    for (auto &ob : observers) {
        ob->notify(*this);
    }
}
void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}
void Subject::setState(State newS) {
    state = newS;
}

State Subject::getState() {
    return state;
}