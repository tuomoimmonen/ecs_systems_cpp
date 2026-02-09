#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    std::cout << "Entity constructor called\n";
}

Entity::~Entity()
{
    std::cout << "\033[31m" << "Entity destructor called" << "\033[0m\n";
}

void Entity::update()
{
    if (!m_components.empty()) {
        for (std::unique_ptr<Component>& c : m_components) {
            c->update();
        }
    }
}

void Entity::add_component(std::unique_ptr<Component> new_component)
{
    new_component->set_owner(this);
    m_components.push_back(std::move(new_component));
}

void Entity::print()
{
    if (!m_components.empty()) {
        for (std::unique_ptr<Component>& c : m_components) {
            c->print();
        }
    }
}
