#pragma once
#include <iostream>


class Soldier{
private:
    int _HP;
    int _DP;
    int _player;


    Soldier();

public:
    Soldier(int HP, int DP, int player) : _HP(HP),_DP(DP),_player(player){}
    int get_player(){
        return _player;
    }
    virtual void activity() = 0;
    virtual ~Soldier() = 0;
};