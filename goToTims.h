#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include "square.h"
#include "player.h"

class GoToTims : public Square {
    Square& tims;
    public:
    GoToTims(int bi, bool prop, Square& tims);
    void land(Player p) override;
};

#endif
