#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager()
{
    std::cout << "EntityManager constructor called\n";
}

EntityManager::~EntityManager()
{
    std::cout << "\033[31m" << "EntityManager constructor called" << "\033[0m\n";
}

void EntityManager::add_entity(std::unique_ptr<Entity> new_entity)
{
    m_entities.push_back(std::move(new_entity));
}

void EntityManager::print()
{
    if (!m_entities.empty()) {
        for (std::unique_ptr<Entity>& e : m_entities) {
            e->print();
        }
    }
}
