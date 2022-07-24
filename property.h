#include "square.h"
class Player;
class Block;

class Property : public Square {
    Player *owner = nullptr;
    Block *block;
    int purchaseCost;
    bool mortgaged = false;
public:
    Property(int bi, int pc, std::string name);
    Player *getOwner();
    Block *getBlock();
    void setBlock(Block* newBlock);
    int getPurchaseCost();
    bool getMortgaged();
    void setOwner(Player *p);
    void mortgage(Player &p);
    void unmortgage(Player &p);
    virtual void payFee(Player &p) = 0;
};