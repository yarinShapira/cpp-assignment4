#include <iostream>
#include "Soldier.hpp"

class ParamedicCommander : public Soldier{
public:
    ParamedicCommander(int player) : Soldier(200, 100, player){}
    void activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    ~ParamedicCommander();
};