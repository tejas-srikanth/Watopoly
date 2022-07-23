#include "needlesHall.h"

void SLC::getEffect() {
    int random = rand() % 18 + 1;
    int balance = p.getBal();
    if (random == 1) {
        p.changeBal(balance - 200);
    } else if (random <= 3) {
        p.chanceBal(balance - 100);
    } else if (random <= 6) {
        p.chanceBal(balance - 50);
    } else if (random <= 12) {
        p.chanceBal(balance + 25);
    } else if (random <= 15) {
        p.chanceBal(balance + 50);
    } else if (random <= 17) {
        p.chanceBal(balance + 100);
    } else {
        p.chanceBal(balance + 200);
    }
}