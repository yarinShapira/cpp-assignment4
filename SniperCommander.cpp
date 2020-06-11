#include "SniperCommander.hpp"
#include "Sniper.hpp"

void SniperCommander::activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location){
    int max = -1;
    std::pair<int,int> target{-1,-1};
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr){
                if (board[i][j]->_player != this->_player){
                    if (board[i][j]->_HP > max){
                        max = board[i][j]->_HP;
                        target = {i,j};
                    }
                }
            }
        }
    }
    if (max > 0) board[target.first][target.second]->injured(this->_DP);
    for (size_t i = 0; i < board.size(); i++){
        for (size_t j = 0; j < board[i].size(); j++){
            if (board[i][j] != nullptr){
                if(board[i][j]->_player ==  this->_player){
                    if (dynamic_cast<Sniper*>(board[i][j]) != nullptr){
                        board[i][j]->activity(board, std::pair<int,int>{i,j});
                    }
                }
            }
        }
    }
}


SniperCommander::~SniperCommander(){

}