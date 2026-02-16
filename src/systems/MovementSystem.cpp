#include "MovementSystem.h"
#include "components/InputComponent.h"
#include "components/TransformComponent.h"
#include "map/Map.h"

#include <iostream>

MomeventSystem::MomeventSystem()
{
    std::cout << "MovementSystem constructor called\n";
}

MomeventSystem::~MomeventSystem()
{
    std::cout << "\033[31m" << "MovementSystem destructor called" << "\033[0m\n";
}

void MomeventSystem::update(EntityManager& entity_manager, const Map& current_map)
{
    for (auto& e : entity_manager.get_entities())
    {
        InputComponent* input = e->get_component<InputComponent>();
        TransformComponent* transform = e->get_component<TransformComponent>();

        if (input && transform)
        {
            transform->set_x(input->get_x_direction());
            transform->set_y(input->get_y_direction());

            int x = transform->get_x();
            int y = transform->get_y();
            if (current_map.is_inside(x, y))
            {
                
            }
        }
    }
}


