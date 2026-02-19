#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(const char new_symbol)
    :m_symbol(new_symbol)
{
    std::cout << "SpriteComponent constructor called\n";

    if (m_texture != nullptr) {
        m_symbol = m_texture->m_symbol;
        std::cout << "SpriteComponent has Texture\n";
    }
}

SpriteComponent::~SpriteComponent()
{
    std::cout << "\033[31m" << "SpriteComponent destructor called" << "\033[0m\n";
}

void SpriteComponent::update()
{

}

void SpriteComponent::print()
{
    std::cout << "SpriteComponent symbol: " << m_symbol << "\n";
}
