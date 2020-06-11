#pragma once

#include <iostream>
#include "Soldier.hpp"

class FootCommander : public Soldier{
public:
    FootCommander(int player) : Soldier(150, 20, player){}
    void activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    std::pair<int,int> search(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number);
    ~FootCommander();
};