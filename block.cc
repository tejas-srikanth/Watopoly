#include "block.h"
#include "player.h"
#include "subject.h"
#include "property.h"
#include "square.h"
#include "state.h"
#include <map>
#include <iostream>
using namespace std;

Block::Block(std::vector<int> bis) {
    for (auto b : bis) {
        ownership.insert(pair<int, Player *>(b, nullptr));
    }
}

void Block::notify(Subject &whoFrom) {
    struct State wF = whoFrom.getState();
    if (wF.notifType == StateType::ChangeOwner) {
        std::map<int, Player *>::iterator it;
        it = ownership.find(wF.boardIndex);
        it->second = wF.owner;
    } else if (wF.notifType == StateType::Landed) {
        if (wF.owner != wF.justLanded) {
            if (wF.property == PropertyType::Academic) {
                academicBlock(whoFrom);
            } else {
                resgymBlock(whoFrom);
            }
        }
    }
}

void Block::academicBlock(Subject &whoFrom) {
    struct State wF = whoFrom.getState();
    Player *owner = wF.owner;
    Player *visitor = wF.justLanded;
    bool monopoly = true;
    std::map<int, Player*>::iterator it = ownership.begin();
    while (it != ownership.end()) {
        if (it->second != owner) {
            monopoly = false;
            break;
        }
    }
    if (monopoly) {        
        wF.condition = 2;
    } else {
        wF.condition = 1;
    }
    whoFrom.setState(wF);
}

void Block::resgymBlock(Subject &whoFrom) {
    struct State wF = whoFrom.getState();
    Player *owner = wF.owner;
    Player *visitor = wF.justLanded;
    int num = 0;
    std::map<int, Player*>::iterator it = ownership.begin();
    while (it != ownership.end()) {
        if (it->second == owner) {
            num++;
        }
    }
    wF.condition = num;
    whoFrom.setState(wF);
}

std::map<int, Player*> Block::getOwnership() {
    return ownership;
}