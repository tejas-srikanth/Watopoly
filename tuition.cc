#include "tuition.h"
#include "property.h"
#include <iostream>

void Tuition::land(Player& p) {
    p.changePos(this->getBoardIndex());
    // setting State s
    struct State s;
    s.notifType = StateType::Landed;
    s.justLanded = &p;
    s.owner = this->getOwner();
    s.property = PropertyType::Special;
    this->setState(s);
    
    char choice;
    while (true) {
        std::cout << "Please choose between paying: a.$300 or b.10% of total worth" << std::endl;
        std::cout << "Enter \"a\" or \"b\" here:";
        char choice;
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 'a') {
            int balance = p.getBal();
            p.changeBal(balance - 150);
            return;
        } else if (choice == 'b') {
            int balance = p.getBal();
            vector<Property> property = p.getAsset();
            for (Property v : property){
                balance += v.getPurchaseCost();
            }
            p.changeBal(balance * 0.9);
            return;
        }
    }
    
}
