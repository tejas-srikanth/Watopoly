#include "tuition.h"
#include "property.h"
#include <iostream>

void Tuition::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    this->setState(s);
    this->notifyObservers();
    
    char choice;
    while (true) {
        std::cout << "Please choose between paying: a.$300 or b.10% of total worth" << std::endl;
        std::cout << "Enter \"a\" or \"b\" here:";
        char choice;
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 'a') {
            p.changeBal(-150);
            return;
        } else if (choice == 'b') {
            p.payTenPercent();
            return;
        }
    }
    
}
