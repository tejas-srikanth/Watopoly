#ifndef __SQUARE__
#define __SQUARE__
#include "subject.h"
class Player;

class Square : public Subject {
    int boardIndex;
public:
    Square(int bi);
    virtual void land(Player &p) = 0;
    int getBoardIndex();
};

#endif