#pragma once
#include <iostream>
#include "Soldier.hpp"

class Paramedic : public Soldier{
public:
    Paramedic(int player) : Soldier(100, 50, player){}
    void activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    ~Paramedic();
};