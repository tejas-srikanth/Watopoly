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
#include <time.h>
using namespace std;

vector<Square*> Board::getSquares(){ return squares; }
vector<Player*> Board::getPlayers(){ return players; }
int Board::getNumPlayers(){ return numPlayers; }
bool Board::getTesting(){ return testing; }

void Board::initalizeSquares(){

    DCTims* dcTims = new DCTims{"DC Tims", 10};

    academicProperties.push_back( new Academic("ML", 1, 40, 50, MLt));
    academicProperties.push_back( new Academic{"AL", 2, 60, 50, ALt });
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

    properties.push_back( academicProperties[0] );
    properties.push_back( academicProperties[1] );
    properties.push_back( new Residence{"MKV", 5, 200});
    properties.push_back( academicProperties[2] );
    properties.push_back( academicProperties[3]);
    properties.push_back( academicProperties[4]);
    properties.push_back( academicProperties[5]);
    properties.push_back( new Gym{"PAC", 12, 150});
    properties.push_back( academicProperties[6]);
    properties.push_back( academicProperties[7]);
    properties.push_back( new Residence{"UWP", 15, 200});
    properties.push_back( academicProperties[8]);
    properties.push_back( academicProperties[9]);
    properties.push_back( academicProperties[10]);
    properties.push_back( academicProperties[11]);
    properties.push_back( academicProperties[12]);
    properties.push_back( academicProperties[13]);
    properties.push_back( new Residence{"V1", 25, 200});
    properties.push_back( academicProperties[14]);
    properties.push_back( academicProperties[15]);
    properties.push_back( new Gym{"CIF", 28, 150});
    properties.push_back( academicProperties[16]);
    properties.push_back( academicProperties[17]);
    properties.push_back( academicProperties[18]);
    properties.push_back(academicProperties[19]);
    properties.push_back( new Residence{"REV", 35, 200});
    properties.push_back( academicProperties[20]);
    properties.push_back( academicProperties[21]);

    squares.push_back( new Osap{"OSAP", 0} );
    squares.push_back( properties[0] );
    squares.push_back( new SLC{"SLC", 2} );
    squares.push_back(properties[1] );
    squares.push_back( new Tuition{"Tuition", 4});
    squares.push_back( properties[2]);
    squares.push_back(properties[3]);
    squares.push_back( new NeedlesHall{"NH", 7});
    squares.push_back( properties[4]);
    squares.push_back( properties[5]);
    squares.push_back( dcTims );
    squares.push_back( properties[6]);
    squares.push_back( properties[7]);

    squares.push_back( properties[8]);
    squares.push_back( properties[9]);
    squares.push_back(properties[10]);
    squares.push_back( properties[11]);
    squares.push_back( new SLC{"SLC", 17} );

    squares.push_back(properties[12]);
    squares.push_back( properties[13]);
    squares.push_back( new GooseNesting{"Goose Nesting", 20});
    squares.push_back( properties[14]);
    squares.push_back( new NeedlesHall{"NH", 22 });

    squares.push_back( properties[15]);
    squares.push_back( properties[16]);
    squares.push_back(properties[17]);

    squares.push_back( properties[18]);
    squares.push_back( properties[19]);
    squares.push_back( properties[20]);
    squares.push_back( properties[21]);
    squares.push_back( new GoToTims{"GoToTims", 30 });

    squares.push_back(properties[22]);
    squares.push_back( properties[23]);
    squares.push_back( new SLC{"SLC", 33});
    squares.push_back( properties[24]);
    squares.push_back( properties[25]);
    squares.push_back( new NeedlesHall{"NH", 36 });

    squares.push_back( properties[26]);
    squares.push_back( new CoopFee{"Coop Fee", 38});
    squares.push_back( properties[27]);

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

    td = new TextDisplay{players};

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
    Block* Res = new Block{vector<int>{5, 15, 25, 35}};
    Block* Gyms = new Block{vector<int>{12, 28}};

    allblocks = {Arts1, Arts2, Eng, Health, Env, Sci1, Sci2, Math, Res, Gyms};
    blocks = {Arts1, Arts2, Eng, Health, Env, Sci1, Sci2, Math};

    for (Block* block: allblocks){
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
        }

        if (p->getBal() < improvementCost){
            cout << "You don't have enough money for this improvement " << endl;
            return false;
        }

        if (b->getImprovement() == 5){
            cout << "You cannot make further improvements on this monopoly " << endl;
            return false;
        }
        b->buyImprovements();
        cout << "Congrats, you bought an improvement on " << b->getName() << "\'s block" << endl;
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
        b->sellImprovements();
        cout << "Congrats, you sold an improvement on " << b->getName() << "\'s block" << endl;
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

void Board::assets(Player* p){
    cout << "Here is " << p->getName() <<"\'s list of assets:" << endl;
    cout << "Properties: ";
    for (int propertyIndex: p->getAssets()){
        cout << squares[propertyIndex]->getName() << '\t';
    }
    cout << endl;
    cout << "Balance: " << p->getBal() << endl;
}

void Board::all(){
    for (auto player: players){
        assets(player);
    }
}

int rollDie(int max){
    if (max == -1){
        srand(time(NULL));
        return rand() % 6 + 1;
    } else {
        return rand() % max + 1;
    }
}

void Board::showOptions(Player* p){
    cout << "It is now " << p->getName() << "\'s turn, here are your options:" << endl;
    cout << "trade <name> <give> <receive>" << endl;
    cout << "improve <property> buy/sell" << endl;
    cout << "mortgage <property>" << endl;
    cout << "unmortgage <property>" << endl;
    cout << "assets" << endl;
    cout << "all" << endl;
    cout << "save <filename>" << endl;
    if (p->getJail()){
        cout << "next (this will end your turn)" << endl;
    } else {
        if (testing){
            cout << "roll <dice1> <dice2> (this will end your turn)" << endl;
        } else {
            cout << "roll (this will end your turn)" << endl;
        }

    }
}

void Board::auction(Property* building){
    int currentBid = building->getPurchaseCost();
    cout << "Auctioning off " << building->getName() << endl;
    cout << "Start the bidding at " << currentBid << endl;
    vector<Player*> auctioners;
    int currAuctioner = 0;
    bool auctionEnded = false;

    for (auto player: players){
        auctioners.push_back(player);
    }
    while (!auctionEnded){
        string s;
        cout << auctioners[currAuctioner]->getName() << ", would you like to withdraw or bid? Type in 'withdraw' or 'bid' then press enter:  ";
        cin >> s;
        if (s.compare("withdraw") == 0){
            auctioners.erase(auctioners.begin() + currAuctioner);
        } else if (s.compare("bid") == 0){
            while (true){
                cout << "How much would you like to bid: ";
                int s;
                cin >> s;
                if (s < currentBid){
                    cout << endl << "Bid must be at least the current bid" << endl;
                    continue;
                } else {
                    currentBid = s;
                    cout << endl << "Bidding is now at " << currentBid << endl;
                    break;
                }
            }
        } else {
            continue;
        }

        if (auctioners.size() == 1){
            Player* winner = auctioners[0];
            cout << "Congrats! " << winner->getName() << " you are the winner!" << endl;
            bool hasBought = buy(winner, building);
            if (hasBought){
                cout << "You bought " << building->getName() << endl;
            }
            auctionEnded = true;
            break;
        }

    }
}

void Board::landOn(Player* currPlayer, Square* landedSquare){
    int boardIndex = landedSquare->getBoardIndex();

    if (landedSquare->isProperty()){
        landedSquare->land(*currPlayer);
        Property* landedProperty;
        for (auto property: properties){
            if (property->getBoardIndex() == landedSquare->getBoardIndex()){
                landedProperty = property;
            }
        }

        if (!landedProperty->getOwner()){
            cout << "Do you want to buy this property?(y/n) " << endl;
            char yesNo;
            cin >> yesNo;
            bool hasBought;
            if (yesNo == 'y'){
                hasBought = buy(currPlayer, landedProperty);
            } else {
                hasBought = false;
            }
            if (!hasBought){
                auction(landedProperty);
            } else {
                cout << "Congrats, you have bought " << landedProperty->getName() << endl;
            }

        } else {
            landedProperty->payFee(*currPlayer);
        }
    }

    else if (boardIndex == 2 || boardIndex == 33){
        landedSquare->land(*currPlayer);
        int newPos = currPlayer->getPos();
        if (newPos < 0){
            newPos += numSquares;
        }
        landOn(currPlayer, squares[newPos]);

    }
    else {
        landedSquare->land(*currPlayer);
    }
}

void Board::raiseMoney(Player* p){
    for (int asset: p->getAssets()){
        for (auto property: academicProperties){
            if (property->getBoardIndex() == asset){
                for (int i=0; i<property->getImprovement(); ++i){
                    improve(p, property, 's');
                }
                mortgage(p, property);
            }
        }
    }
}

void Board::play(){
    int playerIndex = 0;
    bool gameEnded = false;
    cout << *(td);
    int numDoubles = 0;
    showOptions(players[playerIndex]);
    cout << "Enter command: ";
    string commandLine;

    while (!gameEnded){
        Player* currPlayer = players[playerIndex];
        if (numPlayers < 2){
            cout << currPlayer->getName() << " has won the game!" << endl;
            gameEnded = true;
            break;
        }
        getline(cin, commandLine);
        stringstream commandSS = stringstream(commandLine);
        string word;
        vector<string> move;
        while (commandSS >> word){
            move.push_back(word);
        }

        if (move.size() == 0){
            continue;
        }

        if (move[0].compare("roll") == 0){
            if (currPlayer->getJail()){
                cout << "You can't roll, you're in jail. To move on to the next person, type in next" << endl;
                continue;
            }
            int num1 = -1; int num2 = -1;
            int roll1 = 0, roll2 = 0;
            if (testing){
                try{
                    num1 = stoi(move[1]);
                } catch (exception& err){
                    num1 = -1;
                }
                
                try{
                    num2 = stoi(move[2]);
                } catch (exception& err){
                    num2 = -1;
                }

                roll1 = rollDie(num1);
                roll2 = rollDie(num2);

            }
            else {
                roll1 = rollDie(-1);
                roll2 = rollDie(-1);
            }
            int totalRoll = roll1 + roll2;
            int numOsap = 0;
            int currentPos = currPlayer->getPos();
            if (currentPos== 0){
                numOsap++;
                totalRoll--;
                currentPos = 1;
            }

            numOsap += (currentPos + totalRoll - 1) / numSquares;
            int newSquarePos = (currPlayer->getPos() + totalRoll) % numSquares;
            currPlayer->changeBal(200 * numOsap);

            Square* landedSquare = squares[newSquarePos];
            cout << "You rolled a " << roll1 << " and a " << roll2 << endl;
            cout << "You landed on " << landedSquare->getName() << endl;

            landOn(currPlayer, landedSquare);

            if (currPlayer->getBal() < 0){
                cout << "You currently owe more money than you have. Type in one of the following:" << endl;
                cout << "bankruptcy (to declare bankrupcy and drop out)" << endl;
                cout << "raise (to raise money to avoid bankruptcy)" << endl;
                cout << "Type in your choice here: ";
                string s;
                cin >> s;
                bool bankrupt = false;
                if (s.compare("raise") == 0){
                    raiseMoney(currPlayer);

                    if (currPlayer->getBal() < 0){
                        bankrupt = true;
                    }
                } else if (s.compare("bankrupt") == 0){
                    bankrupt = true;
                }

                if (bankrupt){
                    cout << "You are now bankrupt, you will be removed from the game. Hit enter to continue. ";
                    landedSquare->bankrupt(currPlayer);
                    players.erase(players.begin() + playerIndex);
                    numPlayers--;
                    if (players.size() == 1){
                        cout << "Game's over! " << players[0]->getName() << " has won." << endl;
                        return;
                    }
                    for (int asset: currPlayer->getAssets()){
                        Property* theProp;
                        for (auto prop: properties){
                            if (prop->getBoardIndex() == asset){
                                prop->setOwner(nullptr);
                                theProp = prop;
                            }
                        }

                        for (auto acadProp: academicProperties){
                            if (acadProp->getBoardIndex() == asset){
                                acadProp->setMortgage(false);
                                acadProp->setImprovement(0);
                            }
                        }

                        auction(theProp);
                    }
                    delete currPlayer;
                } 
                
                else {
                    cout << "You saved yourself from bankruptcy!" << endl;
                    continue;
                }
                
            }

            if (roll1 != roll2 || currPlayer->getBal() < 0 || currPlayer->getJail()){
                numDoubles = 0;
                if (currPlayer->getBal() < 0){
                    currPlayer = players[playerIndex];
                } else {
                    currPlayer = players[(playerIndex + 1) % players.size()];
                }
                cout << "It is now the next person's turn. Hit enter to continue." << endl;
                cout << *(td);
                showOptions(currPlayer);
            }

            else {
                numDoubles++;
                if (numDoubles == 3){
                    cout << "You rolled 3 doubles, you must go to jail" << endl;
                    currPlayer->setJail(true);
                    currPlayer->changePos(10);
                    landOn(currPlayer, squares[10]);
                    playerIndex = (playerIndex + 1) % players.size();
                    currPlayer = players[playerIndex];
                    cout << "It is now the next person's turn. Hit enter to continue." << endl;
                    cout << *(td);
                    showOptions(currPlayer);
                }

                else {
                    cout << "You rolled doubles, you get another turn" << endl;
                }
            }
        }
        else if (move[0].compare("next")){
            if (!currPlayer->getJail()){
                cout << "You can, and must, roll since you are not in jail. Press enter to continue. " << endl;
                continue;
            }

            cout << "You are in jail. " << endl;
            bool endTurn = false;
            if (currPlayer->getCups() > 0){
                char yn;
                while (true){
                    cout << "You have a cup, would you like to use it (y/n): ";
                    cin >> yn;
                    if (yn == 'y'){
                        currPlayer->setCups(currPlayer->getCups() - 1);
                        currPlayer->setJail(false);
                        dcTims->useCup();
                        cout << "You're out of jail, you can roll on the next turn. Press enter to continue." << endl;
                        endTurn = true;
                        break;
                    } else if (yn == 'n'){
                        cout << "Okay, take your chances then. " << endl;
                        break;
                    } else {
                        continue;
                    }
                }
                if (endTurn){
                    currPlayer = players[(playerIndex + 1) % players.size()];
                    playerIndex = (playerIndex + 1) % players.size();
                    continue;
                }
            }

            cout << "Try rolling doubles to get out of jail:" << endl;
            int num1 = -1; int num2 = -1;
            int roll1 = 0, roll2 = 0;
            if (testing){
                try{
                    string n1;
                    cin >> n1;
                    num1 = stoi(n1);
                } catch (exception& err){
                    num1 = -1;
                }
                
                try{
                    string n2;
                    cin >> n2;
                    num2 = stoi(n2);
                } catch (exception& err){
                    num2 = -1;
                }

                roll1 = rollDie(num1);
                roll2 = rollDie(num2);

            }
            else {
                roll1 = rollDie(-1);
                roll2 = rollDie(-1);
            }
            cout << "You rolled: " << roll1 << " " << roll2 << endl;
            if (roll1 == roll2){
                cout << "You rolled doubles, you're out of jail. Hit enter to continue" << endl;
                currPlayer->setJail(false);
                endTurn = true;
            } else {
                cout << "You did not roll doubles" << endl;
            }

            if (endTurn){
                currPlayer = players[(playerIndex + 1) % players.size()];
                playerIndex = (playerIndex + 1) % players.size();
                continue;
            }
            bool isPaying = false;
            if (currPlayer->getJailRounds() == 3){
                isPaying = true;
            } 
            else{
                char yn;
                while (true){
                    
                    cout << "Do you want to pay 50 dollars to get out of jail (y/n): " << endl;
                    cin  >> yn;
                    if (yn == 'y'){
                        isPaying = true;
                        break;
                    }else if (yn == 'n'){
                        isPaying = false;
                        break;
                    } else {
                        cout << "Invalid response, try again" << endl;
                        continue;
                    }
                }
            }

            if (isPaying){
                currPlayer->changeBal(-50);

                if (currPlayer->getBal() < 0){
                    cout << "You currently owe more money than you have. Type in one of the following:" << endl;
                    cout << "bankruptcy (to declare bankrupcy and drop out)" << endl;
                    cout << "raise (to raise money to avoid bankruptcy)" << endl;
                    cout << "Type in your choice here: " << endl;
                    string s;
                    cin >> s;
                    bool bankrupt = false;
                    if (s.compare("raise") == 0){
                        raiseMoney(currPlayer);

                        if (currPlayer->getBal() < 0){
                            bankrupt = true;
                        }
                    } else if (s.compare("bankrupt") == 0){
                        bankrupt = true;
                    }

                    if (bankrupt){
                        cout << "You are now bankrupt, you will be removed from the game. Hit enter to continue. ";
                        dcTims->bankrupt(currPlayer);
                        players.erase(players.begin() + playerIndex);
                        numPlayers--;
                        if (players.size() == 1){
                            cout << "Game's over! " << players[0]->getName() << " has won." << endl;
                            return;
                        }
                        for (int asset: currPlayer->getAssets()){
                            Property* theProp;
                            for (auto prop: properties){
                                if (prop->getBoardIndex() == asset){
                                    prop->setOwner(nullptr);
                                    theProp = prop;
                                }
                            }

                            for (auto acadProp: academicProperties){
                                if (acadProp->getBoardIndex() == asset){
                                    acadProp->setMortgage(false);
                                    acadProp->setImprovement(0);
                                }
                            }

                            auction(theProp);
                        }
                        delete currPlayer;
                        playerIndex = playerIndex % players.size();
                        currPlayer = players[playerIndex];
                        continue;
                    } 
                    
                    else {
                        currPlayer->setJail(false);
                        cout << "You saved yourself from bankruptcy and you're out of jail!" << endl;
                        playerIndex = (playerIndex + 1) % players.size();
                        currPlayer = players[playerIndex];
                        continue;
                    }
                    
                }



            }

            else {
                cout << "You have skipped your turn, press enter to continue." << endl;
                currPlayer->setJailRounds(currPlayer->getJailRounds() + 1);
                playerIndex = (playerIndex + 1) % players.size();
                currPlayer = players[playerIndex];
                continue;
            }
        }

        else if (move[0].compare("trade")){
            if (move.size() == 4){
                if (isInt(move[2]) && isInt(move[3])){
                    cout << "can't trade money for money" << endl;
                    continue;
                } 

                else if (isInt(move[2])){
                    Property* b2 = nullptr;
                    Player* p2 = nullptr;
                    string propName = move[3];
                    string p2Name = move[1];
                    int m1 = stoi(move[2]);
                    for (auto prop: properties){
                        if (prop->getName().compare(propName) == 0){
                            b2 = prop;
                            break;
                        }
                    }

                    for (auto player: players){
                        if (player->getName().compare(p2Name) == 0){
                            p2 = player;
                            break;
                        }
                    }

                    if (!b2){
                        cout << "No such building" << endl;
                        continue;
                    } 

                    if (!p2){
                        cout << "No such player" << endl;
                        continue;
                    }

                    trade(currPlayer, p2, m1, b2);
                }

                else if (isInt(move[3])){
                    Property* b1 = nullptr;
                    Player* p2 = nullptr;
                    string propName = move[2];
                    string p2Name = move[1];
                    int m2 = stoi(move[3]);
                    for (auto prop: properties){
                        if (prop->getName().compare(propName) == 0){
                            b1 = prop;
                            break;
                        }
                    }

                    for (auto player: players){
                        if (player->getName().compare(p2Name) == 0){
                            p2 = player;
                            break;
                        }
                    }

                    if (!b1){
                        cout << "No such building" << endl;
                        continue;
                    } 

                    if (!p2){
                        cout << "No such player" << endl;
                        continue;
                    }

                    trade(currPlayer, p2, b1, m2);
                }

                else {
                    Property* b1 = nullptr;
                    Property* b2 = nullptr;
                    Player* p2 = nullptr;
                    string prop1Name = move[2];
                    string prop2Name = move[3];
                    string player2Name = move[1];
                    for (auto prop: properties){
                        if (prop->getName().compare(prop1Name) == 0){
                            b1 = prop;
                        }

                        if (prop->getName().compare(prop2Name) == 0){
                            b2 = prop;
                        }
                    }

                    for (auto player: players){
                        if (player->getName().compare(prop1Name) == 0){
                            p2 = player;
                            break;
                        }
                    }

                    if (!b1){
                        cout << "No such building called " << prop1Name << endl;
                        continue; 
                    }

                    if (!b2){
                        cout << "No such building called " << prop2Name << endl; 
                        continue;
                    }

                    if (!p2){
                        cout << "No such player " << endl;
                        continue;
                    }

                    trade(currPlayer, p2, b1, b2);
                }
            }
        }

        else if (move[0].compare("improve") == 0){
            string buildingName = move[1];
            string action = move[2];
            char ac = action.compare("buy") == 0 ? 'b' : 's';

            for (auto acadProp: academicProperties){
                if (acadProp->getName().compare(buildingName) == 0){
                    improve(currPlayer, acadProp, ac);
                    break;
                }
            }
            continue;
        }

        else if (move[0].compare("mortgage") == 0){
            string buildingName = move[1];
            for (auto prop: properties){
                if (prop->getName().compare(buildingName) == 0){
                    mortgage(currPlayer, prop);
                    break;
                }
            }
            continue;
        }

        else if (move[0].compare("unmortgage") == 0){
            string buildingName = move[1];
            for (auto prop: properties){
                if (prop->getName().compare(buildingName) == 0){
                    unmortgage(currPlayer, prop);
                    break;
                }
            }
            continue;
        }

        else if (move[0].compare("assets") == 0){
            assets(currPlayer);
        }

        else if (move[0].compare("all") == 0){
            all();
        }

        else{
            cout << "Please enter a valid command" << endl;
            continue;
        }
    }
}

bool isInt(string s){
    for (char c: s){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

