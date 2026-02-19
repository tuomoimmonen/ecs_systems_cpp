#include "Texture.h"
#include <iostream>

Texture::Texture(char new_symbol)
    :m_symbol(new_symbol)
{
    std::cout << "Texture constructor called\"n";
}

Texture::~Texture()
{
    std::cout << "\033[31m" << "Texture destructor called" << "\033[0m\n";
}
