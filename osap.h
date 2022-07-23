#ifndef _OSAP_H_
#define _OSAP_H_
#include "square.h"
#include "player.h"

class Osap : public Square {
    public:
    void land(Player& p) override;
};

#endif
