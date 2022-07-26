#ifndef _CHANCE_H_
#define _CHANCE_H_
#include <vector>
#include "square.h"
#include "player.h"
#include "dcTims.h"

class Chance : public Square {
    protected:
    DCTims& tims;
    public:
    Chance(int bi, string name, DCTims& tims);
    void land(Player& p) override;
    virtual void getEffect(Player &p) = 0;
};

#endif
