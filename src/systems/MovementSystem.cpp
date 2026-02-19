#include "MovementSystem.h"
#include "components/InputComponent.h"
#include "components/TransformComponent.h"
#include "components/AIComponent.h"
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
        AIComponent* ai = e->get_component<AIComponent>();

        if (input && transform)
        {
            int x_pos = transform->get_x();
            int x_dir = input->get_x_direction();
            int y_pos = transform->get_y();
            int y_dir = input->get_y_direction();

            bool inside = current_map.is_inside(x_pos + x_dir, y_pos + y_dir);
            if (!inside) return;

            transform->add_x(x_dir);
            transform->add_y(y_dir);

            //std::cout << "new x/y: " << transform->get_x() << ", " << transform->get_y() << "\n";
        }
        else if (ai && transform)
        {
            int x_pos = transform->get_x();
            int x_dir = ai->get_x();
            int y_pos = transform->get_y();
            int y_dir = ai->get_y();

            bool inside = current_map.is_inside(x_pos + x_dir, y_pos + y_dir);
            if (!inside) return;

            transform->add_x(x_dir);
            transform->add_y(y_dir);

            //std::cout << "AI new x/y: " << transform->get_x() << ", " << transform->get_y() << "\n";
        }
    }
}


