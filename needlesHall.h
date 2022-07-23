#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "chance.h"

class STC : public Chance {
    public:
    void getEffect(Player &p) override;
};

#endif
