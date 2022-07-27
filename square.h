#ifndef __SQUARE__
#define __SQUARE__
#include "subject.h"
#include <iostream>
using namespace std;
class Player;

class Square : public Subject {
    int boardIndex;
    std::string name;
    bool property;    
public:
    Square(int bi, string name, bool prop = false);
    virtual void land(Player &p) = 0;
    void load(Player &p);
    int getBoardIndex();
    std::string getName();
    bool isProperty();
    void bankrupt(Player *p);
    virtual ~Square();
};

#endif