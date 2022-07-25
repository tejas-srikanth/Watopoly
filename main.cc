#include "board.h"

int main(){
    cout << "How many players will we have: ";
    int x;
    cin >> x;
    Board b{x};
    b.initialize();
    b.play();
}