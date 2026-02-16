#include "InputComponent.h"
#include "TransformComponent.h"
#include <iostream>
#include <limits>


InputComponent::InputComponent()
{
    std::cout << "InputComponent constructor called\n";
}

InputComponent::~InputComponent()
{
    std::cout << "\033[31m" << "InputComponent destructor called" << "\033[0m\n";
}

void InputComponent::update()
{
    // if (TransformComponent* transform = m_owner->get_component<TransformComponent>()) {
    //     transform->set_x(x_direction);
    //     transform->set_y(y_direction);
    // }
}

void InputComponent::print()
{
    std::cout << "InputComponent x/y direction: " << x_direction << ", " << y_direction << "\n";
}

void InputComponent::set_direction(int x_dir, int y_dir)
{
    x_direction = x_dir;
    y_direction = y_dir;
}
