#ifndef __PLAYER__
#define __PLAYER__
#include <vector>
#include "property.h"

class Player {
    int position;
    int balance;
    std::vector<int> assets;
    char piece;
public:
    Player(char p);
    int getPos();
    int getBal();
    std::vector<int> getAssets();
    char getPiece();
    void changePos(int pos);
    void changeBal(int bal);
    void addAssets(int p);
    void delAssets(int p);
};

#endif