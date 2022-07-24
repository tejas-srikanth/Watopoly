#include "board.h"
#include "osap.h"
#include "academic.h"
#include "slc.h"
#include "gym.h"
#include "residence.h"
#include "tuition.h"
#include "needlesHall.h"
#include "gooseNesting.h"
#include "dcTims.h"
#include "goToTims.h"
#include "coopFee.h"
#include "block.h"
#include "observer.h"
#include <map>
#include <algorithm>
using namespace std;

vector<Square*> Board::getSquares(){ return squares; }
vector<Player*> Board::getPlayers(){ return players; }
int Board::getNumPlayers(){ return numPlayers; }
bool Board::getTesting(){ return testing; }

void Board::initalizeSquares(){
    squares.push_back( new Osap{"OSAP", 0} );
    squares.push_back( new Academic{"AL", 1, 40, 50, ALt} );
    squares.push_back( new SLC{"SLC", 2} );
    squares.push_back( new Academic{"ML", 3, 60, 50, MLt} );
    squares.push_back( new Tuition{"Tuition", 4});
    squares.push_back( new Residence{"MKV", 5, 200});
    squares.push_back( new Academic{"ECH", 6, 100, 50, ECHt});
    squares.push_back( new NeedlesHall{"NH", 7});
    squares.push_back( new Academic("PAS", 8, 100, 50, PASt));
    squares.push_back( new Academic("HH", 9, 120, 50, HHt));
    squares.push_back( new DCTims{"DCTims", 10});
    squares.push_back( new Academic{"RCH", 11, 140, 100, RCHt });
    squares.push_back( new Gym{"PAC", 12, 150 });

    squares.push_back( new Academic("DWE", 13, 140, 100, DWEt));
    squares.push_back( new Academic("CPH", 14, 160, 100, CPHt));
    squares.push_back( new Residence{"UWP", 15});
    squares.push_back( new Academic{"LHI", 16, 180, 100, LHIt });
    squares.push_back( new SLC{"SLC", 17 });

    squares.push_back( new Academic("BMH", 18, 180, 100, BMHt));
    squares.push_back( new Academic("OPT", 19, 200, 100, OPTt));
    squares.push_back( new GooseNesting{"Goose Nesting", 20});
    squares.push_back( new Academic{"EV1", 21, 220, 150, EV1t });
    squares.push_back( new NeedlesHall{"NH", 22 });

    squares.push_back( new Academic("EV2", 23, 220, 150, EV2t));
    squares.push_back( new Academic("EV3", 24, 240, 150, EV3t));
    squares.push_back( new Residence{"V1", 25});

    squares.push_back( new Academic("PHYS", 26, 260, 150, PHYSt));
    squares.push_back( new Academic("B1", 27, 260, 150, B1t));
    squares.push_back( new Gym{"CIF", 28});
    squares.push_back( new Academic{"B2", 29, 280, 150, B2t });
    squares.push_back( new GoToTims{"GoToTims", 30 });

    squares.push_back( new Academic("EIT", 31, 300, 200, EITt));
    squares.push_back( new Academic("ESC", 32, 300, 200, ESCt));
    squares.push_back( new SLC{"SLC", 33});
    squares.push_back( new Academic{"C2", 34, 320, 200, C2t });
    squares.push_back( new Residence{"REV", 35});
    squares.push_back( new NeedlesHall{"NH", 36 });

    squares.push_back( new Academic("MC", 37, 350, 200, MCt));
    squares.push_back( new CoopFee{"Coop Fee", 38});
    squares.push_back( new Academic{"DC", 39, 400, 200, DCt });

    properties.push_back(new Academic{"AL", 1, 40, 50, ALt});
    properties.push_back( new Academic{"ML", 3, 60, 50, MLt} );
    properties.push_back( new Residence{"MKV", 5, 200});
    properties.push_back( new Academic{"ECH", 6, 100, 50, ECHt});
    properties.push_back( new Academic("PAS", 8, 100, 50, PASt));
    properties.push_back( new Academic("HH", 9, 120, 50, HHt));
    properties.push_back( new Academic{"RCH", 11, 140, 100, RCHt });
    properties.push_back( new Gym{"PAC", 12, 150 });
    properties.push_back( new Academic("DWE", 13, 140, 100, DWEt));
    properties.push_back( new Academic("CPH", 14, 160, 100, CPHt));
    properties.push_back( new Residence{"UWP", 15});
    properties.push_back( new Academic{"LHI", 16, 180, 100, LHIt });
    properties.push_back( new Academic("BMH", 18, 180, 100, BMHt));
    properties.push_back( new Academic("OPT", 19, 200, 100, OPTt));
    properties.push_back( new Academic{"EV1", 21, 220, 150, EV1t });
    properties.push_back( new Academic("EV2", 23, 220, 150, EV2t));
    properties.push_back( new Academic("EV3", 24, 240, 150, EV3t));
    properties.push_back( new Residence{"V1", 25});
    properties.push_back( new Academic("PHYS", 26, 260, 150, PHYSt));
    properties.push_back( new Academic("B1", 27, 260, 150, B1t));
    properties.push_back( new Gym{"CIF", 28});
    properties.push_back( new Academic{"B2", 29, 280, 150, B2t });
    properties.push_back( new Academic("EIT", 31, 300, 200, EITt));
    properties.push_back( new Academic("ESC", 32, 300, 200, ESCt));
    properties.push_back( new Academic{"C2", 34, 320, 200, C2t });
    properties.push_back( new Residence{"REV", 35});
    properties.push_back( new Academic("MC", 37, 350, 200, MCt));
    properties.push_back( new Academic{"DC", 39, 400, 200, DCt });

    academicProperties.push_back( new Academic("MC", 37, 350, 200, MCt));
    academicProperties.push_back( new Academic{"DC", 39, 400, 200, DCt });
    academicProperties.push_back( new Academic{"ECH", 6, 100, 50, ECHt});
    academicProperties.push_back( new Academic("PAS", 8, 100, 50, PASt));
    academicProperties.push_back( new Academic("HH", 9, 120, 50, HHt));
    academicProperties.push_back( new Academic{"RCH", 11, 140, 100, RCHt });
    academicProperties.push_back( new Academic("DWE", 13, 140, 100, DWEt));
    academicProperties.push_back( new Academic("CPH", 14, 160, 100, CPHt));
    academicProperties.push_back( new Academic{"LHI", 16, 180, 100, LHIt });
    academicProperties.push_back( new Academic("BMH", 18, 180, 100, BMHt));
    academicProperties.push_back( new Academic("OPT", 19, 200, 100, OPTt));
    academicProperties.push_back( new Academic{"EV1", 21, 220, 150, EV1t });
    academicProperties.push_back( new Academic("EV2", 23, 220, 150, EV2t));
    academicProperties.push_back( new Academic("EV3", 24, 240, 150, EV3t));
    academicProperties.push_back( new Academic("PHYS", 26, 260, 150, PHYSt));
    academicProperties.push_back( new Academic("B1", 27, 260, 150, B1t));
    academicProperties.push_back( new Academic{"B2", 29, 280, 150, B2t });
    academicProperties.push_back( new Academic("EIT", 31, 300, 200, EITt));
    academicProperties.push_back( new Academic("ESC", 32, 300, 200, ESCt));
    academicProperties.push_back( new Academic{"C2", 34, 320, 200, C2t });
    academicProperties.push_back( new Academic("MC", 37, 350, 200, MCt));
    academicProperties.push_back( new Academic{"DC", 39, 400, 200, DCt });
}

void Board::initialize(){
    map<char, int> usedPieces = {
        {'G', false},
        {'B', false},
        {'D', false},
        {'P', false},
        {'S', false},
        {'$', false},
        {'L', false},
        {'T', false}        
    };
    vector<char> possiblePieces = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
    vector<string> optionText = {"Goose (G)", "GRT Bus (B)", "Time Hortons Doughnut (D)", "Professor (P)", "Student (S)", "Money ($)", "Laptop (L)", "Pink Tie (T)"};
    vector<string> names;

    for (int i=0; i<numPlayers; ++i){
        string name;
        while (true){
            cout << "Enter your name: ";
            string potentialName;
            cin >> potentialName;
            if (potentialName.compare("BANK") == 0){
                cout << "You cannot be named bank, pick another name." << endl;
                continue;
            }
            bool taken = false;
            for (string name: names){
                if (name.compare(potentialName) == 0){
                    cout << "That name is already taken, pick another one." << endl;
                    taken = true;
                    break;
                }
            }
            if (!taken){
                name = potentialName;
                names.push_back(potentialName);
                break;
            } else {
                continue;
            }
        }

        char piece;
        while (true){
            bool seeAvail;
            while (true){
                cout << "Do you want to see available pieces (y/n): ";
                char c;
                cin >> c;
                cout << endl;
                if (c == 'y' || c == 'Y'){
                    seeAvail = true;
                    break;
                } else if (c == 'n' || c == 'N'){
                    seeAvail = false;
                } else {
                    cout << "Try again" << endl;
                }
            }

            if (seeAvail){
                cout << "These are the available pieces:" << endl;
                int i = 0;
                for (auto cb: usedPieces){
                    char piece = cb.first;
                    char isUsed = cb.second;
                    if (!isUsed){
                        cout << optionText[i] << '\t';
                    }
                }
            }

            cout << endl;
            cout << "Select one piece: ";
            char potentialPiece;
            cin >> potentialPiece;
            if (usedPieces[potentialPiece]){
                cout << "This piece has already been used, please select another" << endl;
                continue;
            }
            if (count(possiblePieces.begin(), possiblePieces.end(), potentialPiece) == 0){
                cout << "This was not one of the options, select another piece" << endl;
                continue;
            }
            piece = potentialPiece;
            usedPieces[piece] = true;
            break;
        }
        players.push_back(new Player{name, piece});
    }

    TextDisplay *td = new TextDisplay{players};

    for (auto square: squares){
        square->attach(td);

    }

    Block* Arts1 = new Block{vector<int>{1, 3}};
    Block* Arts2 = new Block{vector<int>{6, 8, 9}};
    Block* Eng = new Block{vector<int>{11, 12, 14}};
    Block* Health = new Block{vector<int>{16, 18, 19}};
    Block* Env = new Block{vector<int>{21, 23, 24}};
    Block* Sci1 = new Block{vector<int>{26, 27, 29}};
    Block* Sci2 = new Block{vector<int>{31, 32, 34}};
    Block* Math = new Block{vector<int>{37, 39}};

    blocks = {Arts1, Arts2, Eng, Health, Env, Sci1, Sci2, Math};

    for (Block* block: blocks){
        for (auto blockPair: block->getOwnership()){ // iterates through the properties in block
            int boardIndex = blockPair.first;
            squares[boardIndex]->attach(block);
            for (auto property: properties){
                if (property->getBoardIndex() == boardIndex){
                    property->setBlock(block);
                    break;
                }
            }
        }
    }
}
int Board::getBlockImprovements(Block* b){
    int totalImprovements = 0;
    vector<int> props;
    for (auto pair: b->getOwnership()){ // iterate through buildings in block
        props.push_back(pair.first);
    }
    for (auto propertyIndex: props){
        for (auto prop: academicProperties){
            if (prop->getBoardIndex() == propertyIndex){
                totalImprovements += prop->getImprovement();
            }
        }
    }
    return totalImprovements;
}
bool Board::trade(Player* p1, Player* p2, Property* b1, Property* b2){
    if (b1->getOwner() != p1){
        cout << b1->getName() << " is not owned by you. You cannot trade this" << endl;
        return false;
    } 
    
    if (b2->getOwner() != p2){
        cout << b2->getName() << " is not owned by " << p2->getName() << " they cannot trade this" << endl;
        return false;
    }


    Block* block1 = b1->getBlock();
    Block* block2 = b2->getBlock();
    if (getBlockImprovements(block1) != 0){
        cout << "There are improvements in " << b1->getName() << "'s block. So, you cannot trade this." << endl;
        return false;
    }
    if (getBlockImprovements(block2) != 0){
        cout << "There are improvements in " << b2->getName() << "'s block. So, you cannot trade this." << endl;
        return false;
    }
    string acceptOrReject;
    bool hasAccepted;
    cout << p2->getName() << " do you accept this trade? " << endl;
    while (true){
        cin >> acceptOrReject;
        if (acceptOrReject.compare("accept")){
            hasAccepted = true;
            break;
        }

        if (acceptOrReject.compare("reject")){
            hasAccepted = false;
            break;
        }
    }
    if (hasAccepted){
        b1->setOwner(p2);
        b2->setOwner(p1);
        cout << "The trade has gone through!" << endl;
        return true;
    } else {
        cout << "The trade was declined.Sowwy uwu" << endl;
        return false;
    }
}

bool Board::trade(Player* p1, Player* p2, int m1, Property* b2){
    if (b2->getOwner() != p2){
        cout << b2->getName() << " is not owned by " << p2->getName() << " they cannot trade this" << endl;
        return false;
    }

    if (m1 > p1->getBal()){
        cout << "You do not have enough money to make this trade. " << endl;
    }

    Block* block2 = b2->getBlock();

    if (getBlockImprovements(block2) != 0){
        cout << "There are improvements in " << b2->getName() << "'s block. So, you cannot trade this." << endl;
        return false;
    }

    string acceptOrReject;
    bool hasAccepted;
    cout << p2->getName() << " do you accept this trade? " << endl;
    while (true){
        cin >> acceptOrReject;
        if (acceptOrReject.compare("accept")){
            hasAccepted = true;
            break;
        }

        if (acceptOrReject.compare("reject")){
            hasAccepted = false;
            break;
        }
    }

    if (hasAccepted){
        b2->setOwner(p1);
        p1->changeBal(-1 * m1);
        p2->changeBal(m1);
        cout << "The trade has gone through!" << endl;
        return true;
    } else {
        cout << "The trade was declined.Sowwy uwu" << endl;
        return false;
    }

}

bool Board::trade(Player* p1, Player* p2, Property* b1, int m2){
    if (b1->getOwner() != p1){
        cout << b1->getName() << " is not owned by you, so you cannot trade this" << endl;
        return false;
    }

    if (m2 > p2->getBal()){
        cout << p2->getName() << " does not have enough money to make this trade. " << endl;
        return false;
    }

    Block* block1 = b1->getBlock();

    if (getBlockImprovements(block1) != 0){
        cout << "There are improvements in " << b1->getName() << "'s block. So, you cannot trade this." << endl;
        return false;
    }

    string acceptOrReject;
    bool hasAccepted;
    cout << p2->getName() << " do you accept this trade? " << endl;
    while (true){
        cin >> acceptOrReject;
        if (acceptOrReject.compare("accept")){
            hasAccepted = true;
            break;
        }

        if (acceptOrReject.compare("reject")){
            hasAccepted = false;
            break;
        }
    }

    if (hasAccepted){
        b1->setOwner(p2);
        p2->changeBal(-1 * m2);
        p1->changeBal(m2);
        cout << "The trade has gone through!" << endl;
        return true;
    } else {
        cout << "The trade was declined.Sowwy uwu" << endl;
        return false;
    }

}

vector<Academic*> Board::getBuildings(Block* b){
    vector<Academic*> inBlock;
    for (auto boardIndex: b->getOwnership()){
        for (auto prop: academicProperties){
            if (prop->getBoardIndex() == boardIndex.first){
                inBlock.push_back(prop);
            }
        }
    } 
    return inBlock;  
}

bool Board::improve(Player* p, Academic* b, char action){
    int improvementCost = b->getImprovementCost();
    if (action == 'b'){

        vector<Academic*> theBlock = getBuildings(b->getBlock());
        int totalImprovementCost = 0;
        for (auto academicBuilding: theBlock){
            if (academicBuilding->getOwner() != p){
                cout << "You don't own all the buildings in this block" << endl;
                return false;
            }
            totalImprovementCost += academicBuilding->getImprovementCost();
        }

        if (totalImprovementCost < improvementCost){
            cout << "You don't have enough money for this improvement " << endl;
            return false;
        }

        if (b->getImprovement() == 5){
            cout << "You cannot make further improvements on this monopoly " << endl;
            return false;
        }
        for (auto academicBuilding: theBlock){
            academicBuilding->buyImprovements();
        }
        cout << "Congrats, you bought an improvement on " << b->getName() << "'s block" << endl;
        return true;
    } 
    
    else {
        vector<Academic*> theBlock = getBuildings(b->getBlock());

        for (auto academicBuilding: theBlock){
            if (academicBuilding->getOwner() != p){
                cout << "You don't own all the buildings in this block" << endl;
                return false;
            }
        }


        if (b->getImprovement() == 0){
            cout << "You cannot sell further improvements on this monopoly " << endl;
            return false;
        }
        for (auto academicBuilding: theBlock){
            academicBuilding->sellImprovements();
        }
        cout << "Congrats, you sold an improvement on " << b->getName() << "'s block" << endl;
        return true;
    }
}

bool Board::buy(Player* p, Property* b){
    int purchaseCost = b->getPurchaseCost();
    if (p->getBal() < purchaseCost){
        cout << "You don't have enough money to buy " << b->getName() << endl;
        return false;
    }
    b->setOwner(p);
    cout << "Congrats, you bought " << b->getName() << endl;
    return true;
}

bool Board::mortgage(Player* p, Property* b){
    if (b->getOwner() != p){
        cout << "You do not own this property, so you cannot mortgage it " << endl;
        return false;
    }
    b->mortgage(p);
}

bool Board::unmortgage(Player* p, Property* b){
    if (b->getOwner() != p){
        cout << "You do not own this property, so you cannot mortgage it " << endl;
        return false;
    }
    b->unmortgage(p);
}

void Board::setTesting(bool t){ testing = t; }

void Board::play(){
    vector<Player*>::iterator currPlayer = players.begin();

}

