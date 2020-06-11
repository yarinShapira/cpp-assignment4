#pragma once
#include <iostream>
#include <vector>
#include "Soldier.hpp"

class Sniper : public Soldier{
public:
    Sniper(int player) : Soldier(100, 50, player){};
    void activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    ~Sniper();
};