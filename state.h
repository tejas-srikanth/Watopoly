#ifndef __STATE__
#define __STATE__
class Player;
enum class StateType { Landed, BuyImprovements, SellImprovements, ChangeOwner, Mortgage, 
    Unmortgage, Bankrupt };
enum class PropertyType { Academic, Residence, Gym, Special};

struct State {
    StateType notifType;
    PropertyType property; // type of property
    int boardIndex;
    Player *owner;
    Player *justLanded; // player who just landed on the square
    int condition; // used for calculating fee
};

#endif
