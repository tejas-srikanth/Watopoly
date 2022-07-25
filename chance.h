#ifndef _CHANCE_H_
#define _CHANCE_H_
#include <vector>
#include "square.h"
#include "player.h"

class Chance : public Square {
    int totalCups = 0;
    std::vector<Player> cups;
    public:
    Chance(int bi, string name);
    bool useCup(Player& p);
    void land(Player& p) override;
    virtual void getEffect(Player &p);
    int getTimsCup(Player& p);
};

#endif
