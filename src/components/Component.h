#pragma once
#include "entity/Entity.h"

class Entity;

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void update() = 0;
    virtual void print() = 0;

    void set_owner(Entity* new_owner);

private:
    Entity* m_owner;
};