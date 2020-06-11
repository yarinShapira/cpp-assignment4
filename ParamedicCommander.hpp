#include <iostream>
#include "Soldier.hpp"

class ParamedicCommander : public Soldier{
public:
    ParamedicCommander(int player) : Soldier(200, 100, player){}
     std::pair<int,int> activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    ~ParamedicCommander();
};