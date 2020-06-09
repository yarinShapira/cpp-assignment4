#include "Board.hpp"


    // operator for putting soldiers on the game-board during initialization.
    Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
        return board[location.first][location.second];

    }
    
    // operator for reading which soldiers are on the game-board.
    Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void WarGame::Board::move(uint player_number, std::pair<int,int> source, WarGame::Board::MoveDIR direction){
        if (board[source.first][source.second] == nullptr){
            throw std::invalid_argument("source does not contain a soldier");
        }
        if (board[source.first][source.second]->get_player() != player_number){
            throw std::invalid_argument("the player_number does not matche the player_number of thr soldier");
        }
        if (direction == WarGame::Board::MoveDIR::Up){
            if (board[source.first + 1][source.second] == nullptr){
                board[source.first + 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first + 1][source.second]->activity();
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Down){
            if (board[source.first - 1][source.second] == nullptr){
                board[source.first - 1][source.second] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first - 1][source.second]->activity();
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Right){
            if (board[source.first][source.second + 1] == nullptr){
                board[source.first][source.second + 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second + 1]->activity();
            }
            else{
                throw std::invalid_argument("the target location is not available");
            }
        }
        if (direction == WarGame::Board::MoveDIR::Left){
            if (board[source.first][source.second - 1] == nullptr){
                board[source.first][source.second - 1] = &*board[source.first][source.second];
                board[source.first][source.second] = nullptr;
                board[source.first][source.second - 1]->activity();
            }
            else{
                throw std::invalid_argument("the target location is not available");
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