#include "Board.hpp"


    // operator for putting soldiers on the game-board during initialization.
    Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
        return board[location.first][location.second];

    }
    
    // operator for reading which soldiers are on the game-board.
    Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }

    void WarGame::Board::move(uint player_number, std::pair<int,int> source, WarGame::Board::MoveDIR direction){
        if (board[source.first][source.second] == nullptr){
            throw std::invalid_argument("source does not contain a soldier");
        }
        if (board[source.first][source.second]->get_player() != player_number){
            throw std::invalid_argument("the player_number does not matche the player_number of thr soldier");
        }
        if (direction == WarGame::Board::MoveDIR::Up){
            if (board[source.first + 1][source.second] == nullptr && board.size() < source.first + 1){
                board[source.first + 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first + 1][source.second]->activity(board,std::pair<int,int>{source.first + 1,source.second});
            }
            else{
                std::cout << "up " << source.first + 1 << std::endl;
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Down){
            if (board[source.first - 1][source.second] == nullptr && source.first > 0){
                board[source.first - 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first - 1][source.second]->activity(board,std::pair<int,int>{source.first - 1,source.second});
            }
            else{
                std::cout << "Down " << source.first - 1 << std::endl;
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Right){
            if (board[source.first][source.second + 1] == nullptr && source.second + 1 < board[source.first].size()){
                board[source.first][source.second + 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second + 1]->activity(board,std::pair<int,int>{source.first,source.second + 1});
            }
            else{
                std::cout << "Right " << source.second + 1  << std::endl;
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Left){
            if (board[source.first][source.second - 1] == nullptr && source.second > 0){
                board[source.first][source.second - 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second - 1]->activity(board,std::pair<int,int>{source.first,source.second - 1});
            }
            else{
                std::cout << "Left " << source.second - 1 << std::endl;
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (board[target.first][target.second]->_HP < 1){
            delete board[target.first][target.second];
            board[target.first][target.second] = nullptr;
        }
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool WarGame::Board::has_soldiers(uint player_number) const{
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr && player_number == board[i][j]->get_player()) return true;
            }
        }
        return false;
    }

    WarGame::Board::~Board(){
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr){
                    delete board[i][j]; 
                }
            }    
        }
    }