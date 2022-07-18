#ifndef __ACAD__
#define __ACAD__
#include <map>
#include <iostream>
#include "subject.h"
#include "property.h"

class Academic : public Property {
    int improvement;
    std::map<int,int> improvements;
public:
    Academic(int boardIndex, int purchaseCost);
    void land(Player &p);
    void payFee(Player &p);
};

#endif