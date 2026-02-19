#include "AIComponent.h"
#include <iostream>

AIComponent::AIComponent()
{
    srand(std::time(0));
    std::cout << "AIComponent constructor called\n";
}

AIComponent::~AIComponent()
{
    std::cout << "\033[31m" << "AIComponent destructor called" << "\033[0m\n";    

}

void AIComponent::update()
{
    //std::cout << "AIComponent update\n";
    int random_x = rand() % 2;
    int random_y = rand() % 2;
    bool random_dir = rand() % 2;

    if (random_dir) {
        random_x *= -1;
    }
    else {
        random_y *= -1;
    }

    x_direction = random_x;
    y_direction = random_y;
}

void AIComponent::print()
{
    std::cout << "AIComponent direction x/y: " << x_direction << ", " << y_direction << "\n";
}
