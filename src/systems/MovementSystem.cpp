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
            int x_pos = transform->get_x();
            int x_dir = input->get_x_direction();
            int y_pos = transform->get_y();
            int y_dir = input->get_y_direction();

            bool inside = current_map.is_inside(x_pos + x_dir, y_pos + y_dir);
            if (!inside) return;

            transform->add_x(x_dir);
            transform->add_y(y_dir);

            //std::cout << "inside: " << inside << "\n";

            // if (x < 1) {
            //     x = 1;
            //     transform->set_x(x);
            // }
            // else if (x > 18) {
            //     x = 18;
            //     transform->set_x(x);
            // }
            // if (y < 1) {
            //     y = 1;
            //     transform->set_y(y);
            // }
            // else if (y > 8) {
            //     y = 8;
            //     transform->set_y(y);
            // }
                
            std::cout << "new x/y: " << transform->get_x() << ", " << transform->get_y() << "\n";
        }
    }
}


