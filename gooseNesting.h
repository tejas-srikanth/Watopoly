#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_
#include "square.h"
#include "player.h"

class GooseNesting : public Square {
    public:
    void land(Player p) override;
};

#endif
