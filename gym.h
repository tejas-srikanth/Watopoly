#ifndef __GYM__
#define __GYM__
#include "property.h"
#include <iostream>
#include <map>
class Player;

class Gym : public Property{
public:
    Gym(int boardIndex, int purchaseCost, std::string name);
    void land(Player &p);
    void payFee(Player &p);
};

#endif