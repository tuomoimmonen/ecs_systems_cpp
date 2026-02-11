#pragma once
#include "managers/EntityManager.h"
#include "screenbuffer/ScreenBuffer.h"

class RenderSystem
{
public:
    RenderSystem();
    ~RenderSystem();

    void render(EntityManager& entity_manager, ScreenBuffer& buffer);

private:

};