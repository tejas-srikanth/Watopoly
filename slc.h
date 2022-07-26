#ifndef _SLC_H_
#define _SLC_H_
#include "chance.h"
#include "player.h"
#include "dcTims.h"

class SLC : public Chance {
    public:
    SLC(string name, int bi, DCTims& tims);
    void getEffect(Player& p) override;
};

#endif
