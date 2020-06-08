#pragma once
#include <iostream>
#include "Soldier.hpp"

class Sniper : public Soldier{
public:
    Sniper(int player) : Soldier(100, 50, player){};
    void move(WarGame::Board::MoveDIR direction);
    void activity();
};