#ifndef __ACAD__
#define __ACAD__
#include <vector>
#include <iostream>
#include "subject.h"
#include "property.h"

class Academic : public Property {
    int improvement = 0;
    int improvementCost;
    std::vector<int> improvements;
public:
    Academic(std::string name, int boardIndex, int purchaseCost, int ic, std::vector<int> imp);
    int getImprovement();
    void setImprovement(int newimp);
    int getImprovementCost();
    void land(Player &p);
    void payFee(Player &p);
    void buyImprovements();
    void sellImprovements();
    void setOwner(Player *p) override;
};

#endif
