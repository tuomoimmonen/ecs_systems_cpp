#pragma once
#include "entity/Entity.h"
#include <vector>

class EntityManager
{
public:
    EntityManager();
    ~EntityManager();

    void update();

    void add_entity(std::unique_ptr<Entity> new_entity);
    const std::vector<std::unique_ptr<Entity>>& get_entities();

    void print();

private:
    std::vector<std::unique_ptr<Entity>> m_entities;
};
