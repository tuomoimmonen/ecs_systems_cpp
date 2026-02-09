#include "Component.h"
#include <iostream>

Component::Component()
{
    std::cout << "Base Component constructor called\n";

}

Component::~Component()
{
    std::cout << "\033[031m" << "Base Component destructor called" << "\033[0m\n";
}

void Component::set_owner(Entity* new_owner)
{
    m_owner = new_owner;
}
