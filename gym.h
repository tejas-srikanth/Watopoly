#ifndef __GYM__
#define __GYM__
#include "property.h"
#include <iostream>
#include <map>
class Player;

class Gym : public Property{
public:
    Gym(std::string name, int boardIndex, int purchaseCost);
    void land(Player &p);
    void payFee(Player &p);
};

#endif
