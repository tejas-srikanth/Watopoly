#ifndef __RES__
#define __RES__
#include "property.h"
#include <iostream>
#include <map>
class Player;

class Residence : public Property{
    std::map<int,int> costs;
public:
    void land(Player &p);
    void payFee(Player &p);
};

#endif