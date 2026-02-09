#include "TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent(int x_pos, int y_pos)
    :x_position(x_pos), y_position(y_pos)
{
    std::cout << "TransformComponent constructor called\n";

}

TransformComponent::~TransformComponent()
{
    std::cout << "\033[31m" << "TransformComponent destructor called" << "\033[0m\n";
}

void TransformComponent::update()
{

}

void TransformComponent::print()
{
    std::cout << "TransformComponent position: " << x_position << ", " << y_position << "\n";
}
