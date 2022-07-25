#ifndef __PLAYER__
#define __PLAYER__
#include <vector>
#include <iostream>
class Academic;
class Property;
class Player {
    int position;
    int balance = 1500;
    std::vector<int> assets;
    std::vector<Property *> listOfAssets;
    std::vector<Academic *> listOfAcads;
    char piece;
    std::string name;
    bool inJail = false;
    int jailRounds = 0;
    int cups = 0;
public:
    Player(std::string n, char p);
    int getPos();
    int getBal();
    std::vector<int> getAssets();
    std::vector<Academic *> getAcads();
    char getPiece();
    std::string getName();
    bool getJail();
    bool setJail(bool b);
    void changePos(int pos);
    void changeBal(int bal);
    void addAssets(int p);
    void delAssets(int p);
    void addAssets(Property *p);
    void delAssets(Property *p);
    void payTenPercent();
    int getCups();
    void setCups(int c);
};

#endif