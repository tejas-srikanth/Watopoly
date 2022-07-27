#include "player.h"
#include "property.h"
#include "academic.h"
#include <vector>
#include <iostream>
using namespace std;

Player::Player(string n, char p): piece{p}, name{n} {}

int Player::getPos() {
    return position;
}
int Player::getBal() {
    return balance;
}
std::vector<int> Player::getAssets() {
    return assets;
}

std::vector<Property *> Player::getAssetPointers() {
    return listOfAssets;
}

char Player::getPiece() {
    return piece;
}
std::string Player::getName() {
    return name;
}
bool Player::getJail(){
    return inJail;
}

void Player::setJail(bool b) {
    inJail = b;
}

void Player::changePos(int pos) {
    position = pos;
}
void Player::changeBal(int bal, bool load) {
    cout<<"Player "<<this->name<<":"<<endl;
    balance += bal;
    if (!load) {
        if (bal > 0) {
            cout << "You gained " << bal << "." << endl;
        } else if (bal < 0) {
            cout << "You paid " << (-1)*bal << "." << endl;
        }
        cout << "Your new balance is: " << balance << endl;
    } else {
        cout << "Your balance is: " << balance << endl;
    }
    
}

void Player::addAssets(int p) {
    assets.emplace_back(p);
}
void Player::delAssets(int p) {
    int index = 0;
    for (auto b : assets) {
        if (b == p) {
            assets.erase(assets.begin() + index);
            break;
        }
        index++;
    }
}

void Player::addAssets(Property *p) {
    listOfAssets.emplace_back(p);
}
void Player::delAssets(Property *p) {
    int index = 0;
    for (auto b : listOfAssets) {
        if (b == p) {
            listOfAssets.erase(listOfAssets.begin() + index);
            break;
        }
        index++;
    }
}

void Player::payTenPercent() {
    int netWorth = balance;
    for (auto p : listOfAssets) {
        netWorth += p->getPurchaseCost();
    }
    for (auto a : listOfAcads) {
        netWorth += a->getImprovement() * a->getImprovementCost();
    }
    this->changeBal(netWorth * (-0.1));
}

std::vector<Academic *> Player::getAcads() {
    return listOfAcads;
}

int Player::getCups() {
    return cups;
}
void Player::setCups(int c) {
    cups = c;
}

int Player::getJailRounds() {
    return jailRounds;
}
void Player::setJailRounds(int r) {
    jailRounds = r;
}

void Player::addAcad(Academic *p) {
    listOfAcads.emplace_back(p);
}

void Player::delAcad(Academic *p) {
    int index = 0;
    for (auto b : listOfAcads) {
        if (b == p) {
            listOfAcads.erase(listOfAcads.begin() + index);
            break;
        }
        index++;
    }
}

