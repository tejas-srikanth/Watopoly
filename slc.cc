#include "slc.h"

SLC::SLC(int bi, bool prop, Square& tims) : Square{bi}, tims(tims) {}

void SLC::getEffect() {
    int random = rand() % 24 + 1;
    int position = p.getPos();
    if (random <= 3) {
        p.changePos(position - 3);
    } else if (random <= 7) {
        p.changePos(position - 2);
    } else if (random <= 11) {
        p.changePos(position - 1);
    } else if (random <= 14) {
        p.changePos(position + 1);
    } else if (random <= 18) {
        p.changePos(position + 2);
    } else if (random <= 22) {
        p.changePos(position + 3);
    } else if (random <= 23) {
        tims.goToJail(p);
    } else {
        p.changePos(0); // assuming 0 is always osap
    }
}