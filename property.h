#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include "square.h"
class Player;
class Block;

class Property : public Square {
protected:
    Player *owner = nullptr;
    Block *block;
    int purchaseCost;
    bool mortgaged = false;
    bool acad;
public:
    Property(int bi, int pc, std::string name, bool acad = false);
    Player *getOwner();
    Block *getBlock();
    void setBlock(Block* newBlock);
    int getPurchaseCost();
    bool getMortgaged();
    virtual void setOwner(Player *p);

    void mortgage(Player *p);
    void unmortgage(Player *p);
    void setMortgage(bool m);
    virtual void payFee(Player &p) = 0;
    bool isAcad();
};

#endif
