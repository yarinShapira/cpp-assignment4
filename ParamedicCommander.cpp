#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

void ParamedicCommander::activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location){
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
    for (size_t i = 0; i < board.size(); i++){
        for (size_t j = 0; j < board[i].size(); j++){
            if (board[i][j] != nullptr){
                if(board[i][j]->_player ==  this->_player){
                    if (dynamic_cast<Paramedic*>(board[i][j]) != nullptr){
                        board[i][j]->activity(board, std::pair<int,int>{i,j});
                    }
                }
            }
        }
    }
}


ParamedicCommander::~ParamedicCommander(){
    
}