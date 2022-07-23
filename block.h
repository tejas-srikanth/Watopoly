#ifndef __BLOCK__
#define __BLOCK__
#include "subject.h"
#include <map>

class Property;
class Player;

class Block {
    std::map<int, Player*> ownership;
public:
    Block(std::vector<int> bis);
    void notify(Subject &whoFrom);
    void academicBlock(Subject &whoFrom);
    void resgymBlock(Subject &whoFrom);
};

#endif