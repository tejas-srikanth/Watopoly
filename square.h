#ifndef __SQUARE__
#define __SQUARE__
#include "subject.h"
class Player;

class Square : public Subject {
    int boardIndex;
    bool property;
public:
    Square(int bi, bool prop = false);
    virtual void land(Player &p) = 0;
    int getBoardIndex();
    bool isProperty();
};

#endif