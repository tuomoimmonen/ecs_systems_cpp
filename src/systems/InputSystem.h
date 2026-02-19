#pragma once
#include "components/InputComponent.h"
#include "managers/EntityManager.h"
#include "utilities/GameState.h"

class InputSystem
{
public:
    InputSystem();
    ~InputSystem();

    void update(EntityManager& entity_manager, GameState& state);

private:
    
};