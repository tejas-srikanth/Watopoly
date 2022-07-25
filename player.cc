#include "player.h"
#include "property.h"
#include "academic.h"
#include <vector>
#include <iostream>

Player::Player(std::string n, char p): name{n}, piece{p} {}

int Player::getPos() {
    return position;
}
int Player::getBal() {
    return balance;
}
std::vector<int> Player::getAssets() {
    return assets;
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
void Player::changeBal(int bal) {
    balance += bal;
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
            assets.erase(assets.begin() + index);
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
    this->changeBal(netWorth * (-1));
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