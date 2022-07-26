#ifndef __BLOCK__
#define __BLOCK__
#include "observer.h"
#include <map>
#include <vector>

class Player;

class Block : public Observer {
    std::map<int, Player*> ownership;
public:
    Block(std::vector<int> bis);
    void notify(Subject &whoFrom);
    void academicBlock(Subject &whoFrom);
    void resgymBlock(Subject &whoFrom);
    std::map<int, Player*> getOwnership();
};

#endif
