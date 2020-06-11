#pragma once

#include <iostream>
#include <vector>
#include "Soldier.hpp"


class FootSoldier : public Soldier{
public:
    FootSoldier(int player) : Soldier(100, 10, player){}
    std::pair<int,int> activity(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location);
    std::pair<int,int> search(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    ~FootSoldier();
};