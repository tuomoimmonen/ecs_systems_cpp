#include "InputSystem.h"
#include "components/InputComponent.h"
#include "components/TransformComponent.h"
#include <iostream>

InputSystem::InputSystem()
{
    std::cout << "InputSystem constructor called\n";
}

InputSystem::~InputSystem()
{
    std::cout << "\033[31m" << "InputSystem destructor called" << "\033[0m\n";
}

void InputSystem::update(EntityManager& entity_manager)
{
    // get entities
    for (auto& e : entity_manager.get_entities()) {
        InputComponent* input_comp = e->get_component<InputComponent>();

        if (input_comp)
        {
            char input = 'x';
            do
            {
                std::cout << "\ni. inventory\n";
                std::cout << "q. quit\n";
                std::cout << "w. forward\n";
                std::cout << "d. right\n";
                std::cout << "s. down\n";
                std::cout << "a. left\n";
                std::cin >> input;

                switch (input)
                {
                case 'i':
                {
                    // TODO PRINT INVENTORY
                    
                    break;
                }
                case 'q':
                {
                    // TODO END PROGRAM

                    break;
                }
                case 'w':
                {
                    input_comp->set_direction(0, -1);
                    break;
                }
                case 'd':
                {
                    input_comp->set_direction(1, 0);
                    break;
                }
                case 's':
                {
                    input_comp->set_direction(0, 1);
                    break;
                }
                case 'a':
                {
                    input_comp->set_direction(-1, 0);
                    break;
                }
                default:
                {
                    input_comp->set_direction(0, 0);
                    
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                }

            } while (input == 'x');
        }
    }
}
