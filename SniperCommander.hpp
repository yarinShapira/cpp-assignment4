#include <iostream>
#include "Soldier.hpp"

class SniperCommander : public Soldier{
public:
    SniperCommander(int player) : Soldier(120, 100, player){
    }
    void activity(std::vector<std::vector<Soldier*>> board);
    ~SniperCommander();
};