#ifndef _CHANCE_H_
#define _CHANCE_H_
#include <vector>
#include "square.h"
#include "player.h"

class Chance : public Square {
    public:
    Chance(int bi, string name);
    void land(Player& p) override;
    virtual void getEffect(Player &p);
};

#endif
