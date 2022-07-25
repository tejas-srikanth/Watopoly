#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "chance.h"
#include "player.h"

class NeedlesHall : public Chance {
    public:
    NeedlesHall(string name, int bi, DCTims& tims);
    void getEffect(Player &p) override;
};

#endif
