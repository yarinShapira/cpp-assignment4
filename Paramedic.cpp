#include "Paramedic.hpp"

void Paramedic::activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location){
    if (board.size() > location.first - 1){
        if (board[location.first + 1][location.second] != nullptr) board[location.first + 1][location.second]->healing();
    }
    if (-1 < location.first - 1){
        if (board[location.first - 1][location.second] != nullptr) board[location.first - 1][location.second]->healing();
    }
    if (board[location.first].size() > location.second +1){
        if (board[location.first][location.second + 1] != nullptr) board[location.first][location.second + 1]->healing();
    }
    if (-1 < location.second - 1){
        if (board[location.first][location.second - 1] != nullptr) board[location.first][location.second - 1]->healing();
    }
}


Paramedic::~Paramedic(){
    
}