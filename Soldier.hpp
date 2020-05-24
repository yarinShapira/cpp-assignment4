#pragma once
#include <iostream>

class Soldier{
private:
    int _HP;
    int _DP;
    int _player;
    
public:
    Soldier(int HP, int DP, int player){
        this->_HP = HP;
        this->_DP = DP;
        this->_player = player;
    }
    virtual void move()=0;
    virtual void activity()=0;
    void damage();
};