#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "chance.h"
#include "player.h"

class NeedlesHall : public Chance {
    public:
    void getEffect(Player &p) override;
};

#endif
