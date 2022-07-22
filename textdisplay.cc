#include "textdisplay.h"
#include "state.h"
#include <string>
#include <iostream>
#include <fstream>


TextDisplay::TextDisplay(std::vector<Player*> players){
    std::vector<int> properties = {1, 3, 4, 6, 7, 9, 11, 12, 14, 17, 19, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 40};
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
                int newBoardIndex = gridState.boardIndex;
                int oldBoardIndex = positionMap[justLanded];
                positionMap[justLanded] = newBoardIndex;
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

}

int TextDisplay::getBoardRowVal(int boardIndex){
    if (0 <= boardIndex && 10 >= boardIndex){
        return 1;
    }

    else if (11 <= boardIndex && 19 >= boardIndex){
        return 1 + 6 * (boardIndex - 10);
    }

    else if (20 <= boardIndex && 30 >= boardIndex){
        return 61;
    }

    else if (39 >= boardIndex && 30 <= boardIndex) {
        return 1 + 6 * (40 - boardIndex);
    }
}

int TextDisplay::getBoardColVal(int boardIndex){
    if (0 <= boardIndex && 10 >= boardIndex){
        return 1 + (boardIndex - 10) * 10;
    } 

    else if (11 <= boardIndex && 19 >= boardIndex){
        return 91;
    }

    else if (20 <= boardIndex && 30 >= boardIndex){
        return 1 + (30 - boardIndex) * 10;
    }

    else if (39 >= boardIndex && 30 <= boardIndex){
        return 1;
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

