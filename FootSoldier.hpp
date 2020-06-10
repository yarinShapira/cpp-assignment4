#pragma once

#include <iostream>
#include <vector>
#include "Soldier.hpp"


class FootSoldier : public Soldier{
public:
    FootSoldier(int player) : Soldier(100, 10, player){}
    void activity(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location);
    std::pair<int,int> search(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    std::pair<int,int> search_UP(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    std::pair<int,int> search_Down(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    std::pair<int,int> search_Right(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    std::pair<int,int> search_Left(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    ~FootSoldier();
};