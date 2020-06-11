#include <iostream>
#include "Soldier.hpp"

class SniperCommander : public Soldier{
public:
    SniperCommander(int player) : Soldier(120, 100, player){
    }
     std::pair<int,int> activity(std::vector<std::vector<Soldier*>> board ,std::pair<int,int> location);
    ~SniperCommander();
};