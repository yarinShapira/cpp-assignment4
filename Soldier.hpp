#pragma once
#include <iostream>
#include <vector>


class Soldier{
public:
    int _HP;
    int _DP;
    int _player;
    int _start_HP;

    Soldier() = delete;

    Soldier(int HP, int DP, int player) : _HP(HP),_DP(DP),_player(player),_start_HP(HP){}
    int get_player(){
        return _player;
    }
    void injured(int damage){
        this->_HP -= damage;
    }
    void healing(){
        _HP = _start_HP;
    }
    virtual std::pair<int,int> activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location) = 0;
    virtual ~Soldier(){

    }
};
