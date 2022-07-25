#ifndef _DCTIMS_H_
#define _DCTIMS_H_
#include <map>
#include "square.h"
#include "player.h"

class DCTims : public Square {
    public:
    DCTims(string name, int bi);
    void land(Player& p) override;
    void goToJail(Player& p);
    void newRound(Player& p);
    int getRound(Player& p);
    void sendOut(Player& p);

};

#endif
