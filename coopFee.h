#ifndef _COOPFEE_H_
#define _COOPFEE_H_
#include "square.h"
#include "player.h"

class CoopFee : public Square {
    public:
    void land(Player p) override;
};

#endif
