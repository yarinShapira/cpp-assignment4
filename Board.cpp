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
        if (board.size() > source.first + 1){
            if (board[source.first + 1][source.second] == nullptr) {
                board[source.first + 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first + 1][source.second]->activity(board,std::pair<int,int>{source.first + 1,source.second});
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        else{
            throw std::invalid_argument("the target location is out of the borede");
        }
    }
    if (direction == WarGame::Board::MoveDIR::Down){
        if (-1 < source.first - 1){
            if (board[source.first - 1][source.second] == nullptr) {
                board[source.first - 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first - 1][source.second]->activity(board,std::pair<int,int>{source.first - 1,source.second});
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        else{
            throw std::invalid_argument("the target location is out of the borede");
        }
    }
    if (direction == WarGame::Board::MoveDIR::Right){
        if (board[source.first].size() > source.second + 1){
            if (board[source.first][source.second + 1] == nullptr) {
                board[source.first][source.second + 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second + 1]->activity(board,std::pair<int,int>{source.first,source.second + 1});
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        else{
            throw std::invalid_argument("the target location is out of the borede");
        }
    }
    if (direction == WarGame::Board::MoveDIR::Left){
        if (board[source.first].size() > source.second - 1){
            if (board[source.first][source.second - 1] == nullptr) {
                board[source.first][source.second - 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second - 1]->activity(board,std::pair<int,int>{source.first,source.second - 1});
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        else{
            throw std::invalid_argument("the target location is out of the borede");
        }
    }
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            if (board[i][j] != nullptr){
                if (board[i][j]->_HP < 1){
                    delete board[i][j];
                    board[i][j] = nullptr;
                }
            }
        }
        
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