#ifndef _COOP_H_
#define _COOP_H_
#include "square.h"
#include "player.h"

class CoopFee : public Square {
    public:
    CoopFee(std::string name, int index);
    void land(Player& p) override;
};

#endif
