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
    Academic(int boardIndex, int purchaseCost, std::map<int,int> imp);
    int getImprovement();
    void land(Player &p);
    void payFee(Player &p);
    void buyImprovements();
    void sellImprovements();
};

#endif
