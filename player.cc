#include "player.h"
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

bool Player::setJail(bool b) {
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