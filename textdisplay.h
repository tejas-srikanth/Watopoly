#ifndef _TEXT_DISPLAY_H_
#define _TEXT_DISPLAY_H_

#include <map>
#include "player.h"
#include "observer.h"
#include <iostream>
#include <vector>
#include <string>
//#include "building.h"

class TextDisplay: public Observer{
    std::map<Player*, int> positionMap;
    std::map<int, int> buildingImprovements;
    std::map<int, char> ownerMap;
    std::vector<std::vector<char>> board;
    public:
        TextDisplay(std::vector<Player*> players);
        void notify(Subject& whoNotified);
        int getBoardColVal(int boardIndex);
        int getBoardRowVal(int boardIndex);
        void updatePlayersOnSquare(int boardIndex, std::string players);
        void showImprovements(int boardIndex);
        void updateOwner(int boardIndex, char owner);
        void mortgage(int boardIndex);
        void unmortgage(int boardIndex);

    
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};


#endif 
