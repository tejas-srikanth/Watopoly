#include "player.h"
#include <vector>

int Player::getPos() {
    return position;
}
int Player::getBal() {
    return balance;
}
std::vector<int> Player::getAssets() {
    return assets;
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
        }
        index++;
    }
}