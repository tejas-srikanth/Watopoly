#ifndef _COOPFEE_H_
#define _COOPFEE_H_
#include "square.h"
#include "player.h"

class Tuition : public Square {
    public:
    Tuition(std::string name, int index);
    void land(Player& p) override;
};

#endif
