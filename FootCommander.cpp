#include "FootCommander.hpp"
#include "FootSoldier.hpp"


 void FootCommander::activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location){
    std::pair<int,int> target = search(board, location, this->get_player());
    if (target.first != -1){
        board[target.first][target.second]->injured(this->_DP);
    }
    for (size_t i = 0; i < board.size(); i++){
        for (size_t j = 0; j < board[i].size(); j++){
            if (board[i][j] != nullptr){
                if(board[i][j]->_player ==  this->_player){
                    if (dynamic_cast<FootSoldier*>(board[i][j]) != nullptr){
                        board[i][j]->activity(board, std::pair<int,int>{i,j});
                    }
                }
            }
        }
    }
}

std::pair<int,int> FootCommander::search(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
    std::pair<int,int> ans {-1,-1};
    int min = -1;
    int temp;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr){
                if (board[i][j]->get_player() != player_number) {
                    temp = (abs(location.first - i)) + (abs(location.second - j));
                    if (temp < min || min == -1){
                        min = temp;
                        ans = {i,j};
                    }
                }
            }
        }
            
    }
    return ans;
}


FootCommander::~FootCommander(){
    
}