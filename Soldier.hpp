#pragma once
#include <iostream>

class Soldier{
private:
    int _HP;
    int _DP;
    int _player;
    
public:
    Soldier(int HP, int DP, int player) : _HP(HP),_DP(DP),_player(player){}
    virtual void move() = 0;
    virtual void activity() = 0;
};