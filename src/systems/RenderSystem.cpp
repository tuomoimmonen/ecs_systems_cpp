#include "RenderSystem.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include <iostream>

RenderSystem::RenderSystem()
{
    std::cout << "RenderSystem constructor called\n";
}

RenderSystem::~RenderSystem()
{
    std::cout << "\033[31m" << "RenderSystem destructor called" << "\033[0m\n";

}

void RenderSystem::render(EntityManager& entity_manager, ScreenBuffer& buffer)
{
    std::cout << "\n\033[33m" << "RenderSystem rendering" << "\033[0m\n";
    for (auto& entity : entity_manager.get_entities())
    {
        TransformComponent* transform = entity->get_component<TransformComponent>();
        SpriteComponent* sprite = entity->get_component<SpriteComponent>();
        
        if (transform && sprite)
        {
            int x = transform->get_x();
            int y = transform->get_y();

            buffer.draw_pixel(x, y, sprite->get_symbol());
        }
    }

    buffer.draw();
}