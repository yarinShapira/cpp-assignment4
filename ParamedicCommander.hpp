#include <iostream>
#include "Soldier.hpp"

class ParamedicCommander : public Soldier{
public:
    ParamedicCommander(int player) : Soldier(200, 100, player){}
    void activity();
    ~ParamedicCommander();
};