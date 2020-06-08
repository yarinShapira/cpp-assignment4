#pragma once

#include <iostream>
#include "Soldier.hpp"
#include "Board.hpp"

class FootSoldier : public Soldier{
public:
    FootSoldier(int player) : Soldier(100, 10, player){

    }

    void move(WarGame::Board::MoveDIR direction);
    void activity();
};