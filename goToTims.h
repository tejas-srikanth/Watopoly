#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include "square.h"
#include "player.h"
#include "dcTims.h"

class GoToTims : public Square {
    DCTims& tims;
    public:
    GoToTims(int bi, string name, bool prop, DCTims& tims);
    void land(Player& p) override;
};

#endif
