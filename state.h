#ifndef __STATE__
#define __STATE__
enum class StateType { Landed, BuyImprovements, SellImprovements, ChangeOwner, Mortgage, 
    Unmortgage };
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