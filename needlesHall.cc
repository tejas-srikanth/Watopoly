#include "needlesHall.h"

void NeedlesHall::getEffect(Player& p) {
    int random = rand() % 18 + 1;
    if (random == 1) {
        p.changeBal(-200);
    } else if (random <= 3) {
        p.changeBal(-100);
    } else if (random <= 6) {
        p.changeBal(-50);
    } else if (random <= 12) {
        p.changeBal(25);
    } else if (random <= 15) {
        p.changeBal(50);
    } else if (random <= 17) {
        p.changeBal(100);
    } else {
        p.changeBal(200);
    }
}
