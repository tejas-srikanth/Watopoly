#include "board.h"
#include <iostream>
#include <string>
using namespace std;
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
        string tmp = argv[1];
        if (tmp.compare("-load") == 0) {
            int n;
            string filename = "watopoly.txt";
            if (argc == 3) {
                filename = argv[2];
            }
            ifstream myfile; 
            myfile.open(filename); 
            myfile>>n;
            Board b{n};
            b.loadGame(filename);
        } else if (tmp.compare("-testing") == 0) {
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