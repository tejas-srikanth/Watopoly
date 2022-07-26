#include "board.h"

int main(){
    cout << "How many players will we have: ";
    int x;
    cin >> x;
    while ( x > 6) {
        cout << "You cannot have more than 6 players." <<endl;
        cout << "How many players will we have: ";
        cin >> x;
    }
    Board b{x};
    b.initialize();
    b.play();
}