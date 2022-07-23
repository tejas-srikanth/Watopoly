#ifndef _SLC_H_
#define _SLC_H_
#include "chance.h"
#include "player.h"

class SLC : public Chance {
    Square& tims;
    public:
    SLC(int bi, bool prop, Square& tims);
    void getEffect(Player& p) override;
};

#endif
