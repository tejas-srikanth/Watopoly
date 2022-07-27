#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include "player.h"
#include "square.h"
#include "textdisplay.h"
#include "property.h"
#include "dcTims.h"

class Board{
    std::vector<Square*> squares;
    std::vector<Player*> players;
    std::vector<Property*> properties;
    std::vector<Academic*> academicProperties;
    int numPlayers;
    bool testing = false;
    int round = 0;
    int numDoubles = 0;
    int numSquares = 40;
    std::vector<int> ALt = {2, 10, 30, 90, 160, 250};
    std::vector<int> MLt = {4, 20, 60, 180, 320, 450};
    std::vector<int> ECHt = {6, 30, 90, 270, 400, 550};
    std::vector<int> PASt = {6, 30, 90, 270, 400, 550};
    std::vector<int> HHt = {8, 40, 100, 300, 450, 600};
    std::vector<int> RCHt = {10, 50, 150, 450, 625, 750};
    std::vector<int> DWEt = {10, 50, 150, 450, 625, 750};
    std::vector<int> CPHt = {12, 60, 180, 500, 700, 900};

    std::vector<int> LHIt = {14, 70, 200, 550, 750, 950};
    std::vector<int> BMHt = {14, 70, 200, 550, 750, 950};
    std::vector<int> OPTt = {16, 80, 220, 600, 800, 1000};
    std::vector<int> EV1t = {18, 90, 250, 700, 875, 1050};
    std::vector<int> EV2t = {18, 90, 250, 700, 875, 1050};
    std::vector<int> EV3t = {20, 100, 300, 750, 925, 1100};
    std::vector<int> PHYSt = {22, 110, 330, 800, 975, 1150};
    std::vector<int> B1t = {22, 110, 330, 800, 975, 1150};

    std::vector<int> B2t = { 24, 120, 360, 850, 1025, 1200 };
    std::vector<int> EITt = { 26, 130 ,390 ,900 ,1100, 1275 };
    std::vector<int> ESCt = { 26, 130, 390, 900 ,1100 ,1275 };
    std::vector<int> C2t = { 28, 150, 450 ,1000 ,1200 ,1400 };
    std::vector<int> MCt = { 35, 175, 500, 1100, 1300, 1500 };
    std::vector<int> DCt = {50, 200, 600 ,1400 ,1700 ,2000};
    std::vector<Block*> blocks;
    std::vector<Block*> allblocks;
    DCTims* dcTims;
    TextDisplay* td;
    public:
        Board(int numPlayers);
        ~Board();
        bool getTesting();
        std::vector<Square*> getSquares();
        std::vector<Player*> getPlayers();
        int getNumPlayers();
        void initializeSquares();
        void initialize();
        void roll();
        void next();
        bool trade(Player* p1, Player* p2, Property* b1, Property* b2);
        bool trade(Player* p1, Player* p2, Property* b1, int money);
        bool trade(Player* p1, Player* p2, int money, Property* b1);
        int getBlockImprovements(Block* b);
        bool improve(Player* p, Academic* b, char action);
        bool buy(Player* p, Property* b);
        void saveGame(std::string filename="watopoly.txt");
        void loadGame(std::string filename="watopoly.txt");
        std::vector<Academic*> getBuildings(Block* b);
        void play();
        void auction(Property* building);
        void setTesting(bool t);
        bool mortgage(Player* p, Property* b);
        bool unmortgage(Player* p, Property* b);
        void assets(Player* p);
        void showOptions(Player* p);
        void landOn(Player* p, Square* sq);
        void raiseMoney(Player* p);
        void negativeBalance(Player* p, Square* sq, int playerIndex);
        void all();
        bool isInt(string s);
        bool isAcademic(Property* p);
        std::pair<int, int> rollDice(std::string s1, std::string s2);
        //void playerBankruptcy(Player* p1, Player* p2);


};


#endif