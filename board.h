#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.h"
#include "square.h"
#include "textdisplay.h"
#include "property.h"

class Board{
    std::vector<Square*> squares;
    std::vector<Player*> players;
    std::vector<Property*> property;
    int numPlayers;
    bool testing;
    std::vector<int> AL = {2, 10, 30, 90, 160, 250};
    std::vector<int> ML = {4, 20, 60, 180, 320, 450};
    std::vector<int> ECH = {6, 30, 90, 270, 400, 550};
    std::vector<int> PAS = {6, 30, 90, 270, 400, 550};
    std::vector<int> HH = {8, 40, 100, 300, 450, 600};
    std::vector<int> RCH = {10, 50, 150, 450, 625, 750};
    std::vector<int> DWE = {10, 50, 150, 450, 625, 750};
    std::vector<int> CPH = {12, 60, 180, 500, 700, 900};

    std::vector<int> LHI = {14, 70, 200, 550, 750, 950};
    std::vector<int> BMH = {14, 70, 200, 550, 750, 950};
    std::vector<int> OPT = {16, 80, 220, 600, 800, 1000};
    std::vector<int> EV1 = {18, 90, 250, 700, 875, 1050};
    std::vector<int> EV2 = {18, 90, 250, 700, 875, 1050};
    std::vector<int> EV3 = {20, 100, 300, 750, 925, 1100};
    std::vector<int> PHYS = {22, 110, 330, 800, 975, 1150};
    std::vector<int> B1 = {22, 110, 330, 800, 975, 1150};

    std::vector<int> B2 = { 24, 120, 360, 850, 1025, 1200 };
    std::vector<int> EIT = { 26, 130 ,390 ,900 ,1100, 1275 };
    std::vector<int> ESC = { 26, 130, 390, 900 ,1100 ,1275 };
    std::vector<int> C2 = { 28, 150, 450 ,1000 ,1200 ,1400 };
    std::vector<int> MC = { 35, 175, 500, 1100, 1300, 1500 };
    std::vector<int> DC = {50, 200, 600 ,1400 ,1700 ,2000};

    public:
        Board(int numPlayers);
        bool getTesting();
        std::vector<Square*> getSquares();
        std::vector<Player*> getPlayers();
        int getNumPlayers();
        void initalizeSquares();
        void initialize();
        void roll();
        void next();
        void trade(Player* p1, Player* p2, Property* b1, Property* b2);
        void trade(Player* p1, Player* p2, Property* b1, int money);
        void trade(Player* p1, Player* p2, int money, Property* b1);
        void improve(Player* p, Property* b);
        void buy(Player* p, Property* b);
        void saveGame(std::string filename="watopoly.txt");
        void loadGame(std::string filename="watopoly.txt");
        void play();
        void setTesting();


};


#endif