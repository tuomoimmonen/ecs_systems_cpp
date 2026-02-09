#pragma once
#include "components/Component.h"
#include <vector>
#include <memory>

class Component;

class Entity
{
public:
    Entity();
    ~Entity();

    void update();
    void add_component(std::unique_ptr<Component> new_component);

    void print();

    template<typename Type>
    Type* get_component()
    {
        for (std::unique_ptr<Component>& c : m_components) {
            Type* raw_pointer = dynamic_cast<Type*>(c.get());

            if (raw_pointer) {
                return raw_pointer;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<Component>> m_components;

};