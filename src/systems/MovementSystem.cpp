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
            transform->add_x(input->get_x_direction());
            transform->add_y(input->get_y_direction());

            int x = transform->get_x();
            int y = transform->get_y();

            if (x < 1) {
                x = 1;
                transform->set_x(x);
            }
            else if (x > 18) {
                x = 18;
                transform->set_x(x);
            }
            if (y < 1) {
                y = 1;
                transform->set_y(y);
            }
            else if (y > 7) {
                y = 7;
                transform->set_y(y);
            }
                
            std::cout << "new x/y: " << transform->get_x() << ", " << transform->get_y() << "\n";
        }
    }
}


