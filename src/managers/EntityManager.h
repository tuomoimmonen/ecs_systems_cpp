#pragma once
#include "entity/Entity.h"
#include <vector>

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    void add_entity(std::unique_ptr<Entity> new_entity);

    void print();

private:
    std::vector<std::unique_ptr<Entity>> m_entities;
};
