#ifndef __STATE__
#define __STATE__
<<<<<<< HEAD
#include "player.h"

enum class StateType { Landed, Improvements, ChangeOwner };
=======
enum class StateType { Landed, BuyImprovements, SellImprovements, ChangeOwner, Mortgage, 
    Unmortgage };
>>>>>>> 9183f02ffea3632057dd1c08f46678c708250508
enum class PropertyType { Academic, Residence, Gym};

struct State {
    StateType notifType;
    PropertyType property; // type of property
    int boardIndex;
    Player *owner;
    Player *justLanded; // player who just landed on the square
    int condition; // used for calculating fee
};

#endif