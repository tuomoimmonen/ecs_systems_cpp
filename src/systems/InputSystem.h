#pragma once
#include "components/InputComponent.h"
#include "managers/EntityManager.h"

class InputSystem
{
public:
    InputSystem();
    ~InputSystem();

    void update(EntityManager& entity_manager);

private:
    
};