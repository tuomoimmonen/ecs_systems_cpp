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

void EntityManager::update()
{
    // update all the entities
    if (!m_entities.empty()) {
        for (auto& e : m_entities) {
            e->update();
        }
    }
}

void EntityManager::add_entity(std::unique_ptr<Entity> new_entity)
{
    m_entities.push_back(std::move(new_entity));
}

const std::vector<std::unique_ptr<Entity>>& EntityManager::get_entities()
{
    return m_entities;
}

void EntityManager::print()
{
    if (!m_entities.empty()) {
        for (std::unique_ptr<Entity>& e : m_entities) {
            e->print();
        }
    }
}
