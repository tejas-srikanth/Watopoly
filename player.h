#ifndef __PLAYER__
#define __PLAYER__
#include <vector>
#include "property.h"
#include <iostream>

class Player {
    int position;
    int balance = 1500;
    std::vector<int> assets;
    char piece;
    std::string name;
    bool inJail = false;
public:
    Player(std::string n, char p);
    int getPos();
    int getBal();
    std::vector<int> getAssets();
    char getPiece();
    std::string getName();
    bool getJail();
    bool setJail(bool b);
    void changePos(int pos);
    void changeBal(int bal);
    void addAssets(int p);
    void delAssets(int p);
};

#endif