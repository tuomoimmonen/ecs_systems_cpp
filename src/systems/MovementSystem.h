#pragma once
#include "managers/EntityManager.h"
#include "map/Map.h"

class MomeventSystem
{
public:
    MomeventSystem();
    ~MomeventSystem();

    void update(EntityManager& entity_manager, const Map& current_map);
    
private:
    

};