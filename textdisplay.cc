#include "textdisplay.h"
#include "state.h"
#include "subject.h"
#include <string>
#include <iostream>
#include <fstream>

class Subject;

TextDisplay::TextDisplay(std::vector<Player*> players){
    std::vector<int> properties = {1, 3, 5, 6, 8, 9, 11, 12, 13, 14, 15, 16, 18, 19, 21, 23, 24, 25, 26, 27, 28, 29, 31, 32, 34, 35, 37, 39};
    for (auto player: players){
        positionMap[player] = 0;
    }

    for (int p: properties){
        buildingImprovements[p] = 0;
        ownerMap[p] = ' ';
    }

    std::ifstream infile("board.txt");
    std::string line;
    while (getline(infile, line)){
        std::vector<char> row;
        for (int col=0; col<line.length(); ++col){
            row.push_back(line[col]);
        }
        board.push_back(row);
    }

}

void TextDisplay::notify(Subject& whoNotified){
    State gridState = whoNotified.getState();

    if (gridState.notifType == StateType::Landed){
        Player* justLanded = gridState.justLanded;
        int oldBoardIndex = -1;
        int newBoardIndex = -1;
        for (auto& playerPair: positionMap){
            Player* player = playerPair.first;
            if (player == justLanded){
                newBoardIndex = gridState.boardIndex;
                oldBoardIndex = positionMap[justLanded];
                positionMap[justLanded] = newBoardIndex;
                break;
            }
        }

        std::string oldSquarePlayers = "";
        std::string newSquarePlayers = "";
        for (auto& playerPair: positionMap){
            Player* player = playerPair.first;
            int onSquare = playerPair.second;
            if (onSquare == newBoardIndex){
                newSquarePlayers += player->getPiece();
            }
            else if (onSquare == oldBoardIndex){
                oldSquarePlayers += player->getPiece();
            }
        }

        updatePlayersOnSquare(newBoardIndex, newSquarePlayers);
        updatePlayersOnSquare(oldBoardIndex, oldSquarePlayers);
        
    }

    else if (gridState.notifType == StateType::BuyImprovements){
        int building = gridState.boardIndex;
        buildingImprovements[building]++;
        showImprovements(gridState.boardIndex);
    }

    else if (gridState.notifType == StateType::SellImprovements){
        int building = gridState.boardIndex;
        buildingImprovements[building]--;
        showImprovements(gridState.boardIndex);
    }

    else if (gridState.notifType == StateType::SetImprovements){
        int building = gridState.boardIndex;
        buildingImprovements[building] = gridState.condition;
        showImprovements(gridState.boardIndex);
    }

    else if (gridState.notifType == StateType::ChangeOwner){
        int boardIndex = gridState.boardIndex;
        Player* owner = gridState.owner;
        char piece = owner->getPiece();
        ownerMap[boardIndex] = piece;
        updateOwner(boardIndex, piece);
    }

    else if (gridState.notifType == StateType::Mortgage){
        buildingImprovements[gridState.boardIndex] = 0;
        mortgage(gridState.boardIndex);
    }

    else if (gridState.notifType == StateType::Unmortgage){
        buildingImprovements[gridState.boardIndex] = 0;
        unmortgage(gridState.boardIndex);
    }

    else if (gridState.notifType == StateType::Bankrupt){
        positionMap.erase(gridState.justLanded);
        for (auto ownerPair: ownerMap){
            if (ownerPair.second == gridState.justLanded->getPiece()){
                updateOwner(ownerPair.first, ' ');
            }
        }
    }

}

int TextDisplay::getBoardRowVal(int boardIndex){
    if (0 <= boardIndex && 10 >= boardIndex){
        return 61;
    }

    else if (11 <= boardIndex && 19 >= boardIndex){
        return 1 + 6 * (20 - boardIndex);
    }

    else if (20 <= boardIndex && 30 >= boardIndex){
        return 1;
    }

    else if (39 >= boardIndex && 30 <= boardIndex) {
        return 1 + 6 * (boardIndex - 30);
    }
}

int TextDisplay::getBoardColVal(int boardIndex){
    if (0 <= boardIndex && 10 >= boardIndex){
        return 1 + (10 - boardIndex) * 10;
    } 

    else if (11 <= boardIndex && 19 >= boardIndex){
        return 1;
    }

    else if (20 <= boardIndex && 30 >= boardIndex){
        return 1 + (boardIndex - 20) * 10;
    }

    else if (39 >= boardIndex && 30 <= boardIndex){
        return 91;
    }
}

void TextDisplay::updatePlayersOnSquare(int boardIndex, std::string players){
    int row = getBoardRowVal(boardIndex);
    int col = getBoardColVal(boardIndex);
    int playerRow = row + 4;
    for (int i=0; i<8 - players.length(); ++i){
        players += " ";
    }

    for (int i=0; i<players.length(); ++i){
        board[playerRow][col + i] = players[i];
    }
}

void TextDisplay::showImprovements(int boardIndex){
    int row = getBoardRowVal(boardIndex);
    int col = getBoardColVal(boardIndex);
    int numImprovements = buildingImprovements[boardIndex];
    int i = 0;
    for (int j=0; j<8; ++j){
        if (i < numImprovements){
            board[row][col + j] = 'I';
        } else {
            board[row][col + j] = ' ';
        }
        i++;
    }

}

void TextDisplay::updateOwner(int boardIndex, char owner){
    int row = getBoardRowVal(boardIndex);
    int col = getBoardColVal(boardIndex);
    board[row + 3][col] = 'O';
    board[row + 3][col + 1] = ':';
    board[row + 3][col + 2] = ' ';
    board[row + 3][col + 3] = owner;
}

void TextDisplay::mortgage(int boardIndex){
    int row = getBoardRowVal(boardIndex);
    int col = getBoardColVal(boardIndex);
    showImprovements(boardIndex);
    board[row][col] = 'M';
}

void TextDisplay::unmortgage(int boardIndex){
    int row = getBoardRowVal(boardIndex);
    int col = getBoardColVal(boardIndex);
    board[row][col] = ' ';
}

std::ostream& operator<<(std::ostream& out, const TextDisplay &td){
    for (auto row: td.board){
        for (auto ch: row){
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

