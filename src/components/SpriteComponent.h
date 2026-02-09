#pragma once
#include "Component.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent(const char new_symbol = 'D');
    ~SpriteComponent();

    virtual void update() override;
    virtual void print() override;

    void set_symbol(const char new_symbol) { m_symbol = new_symbol; }
    const char get_symbol() const { return m_symbol; }

private:
    char m_symbol = 'D';

};

