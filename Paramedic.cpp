#include "Paramedic.hpp"

 std::pair<int,int> Paramedic::activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location){
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
    return std::pair<int,int>{-1,-1};
}


Paramedic::~Paramedic(){
    
}