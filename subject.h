#ifndef __SUBJECT__
#define __SUBJECT__
#include "state.h"
#include <vector>

class Observer;

class Subject {
    std::vector<Observer*> observers;
    State state;
public:
    void notifyObservers();
    void attach(Observer *o);
    void setState(State newS);
    State getState();
};

#endif