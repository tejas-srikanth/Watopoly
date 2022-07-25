#ifndef _SLC_H_
#define _SLC_H_
#include "chance.h"
#include "player.h"
#include "dcTims.h"

class SLC : public Chance {
    DCTims& tims;
    public:
    SLC(int bi, string name, bool prop, DCTims& tims);
    void getEffect(Player& p) override;
};

#endif
