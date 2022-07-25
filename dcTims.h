#ifndef _DCTIMS_H_
#define _DCTIMS_H_
#include <map>
#include "square.h"
#include "player.h"

class DCTims : public Square {
    int totalCups = 0;
    public:
    DCTims(string name, int bi);
    void land(Player& p) override;
    bool useCup(Player& p);
    void goToJail(Player& p);
    void newRound(Player& p);
    void sendOut(Player& p);
};

#endif
