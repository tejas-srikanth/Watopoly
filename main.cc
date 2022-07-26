#include "board.h"

int main(int argc, char* argv[]){
    if (argc == 1) {
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
    } else {
        if (argv[1] == "load") {
            int n;
            string filename = "watopoly.txt";
            if (argc == 3) {
                filename = argv[2];
            }
            ifstream myfile; 
            myfile.open(filename); 
            myfile>>n;
            Board b{n};
            b.loadGame();
        } else if (argv[1] == "testing") {
            cout << "How many players will we have: ";
            int x;
            cin >> x;
            while ( x > 6) {
                cout << "You cannot have more than 6 players." <<endl;
                cout << "How many players will we have: ";
                cin >> x;
            }
            Board b{x};
            b.setTesting(true);
            b.initialize();
            b.play();
        }
    }

    
}