#include "ScreenBuffer.h"
#include <iostream>

ScreenBuffer::ScreenBuffer()
{
    std::cout << "ScreenBuffer constructor called\n";

}

ScreenBuffer::~ScreenBuffer()
{
    std::cout << "\033[31m" << "ScreenBuffer destructor called" << "\033[0m\n";

}

void ScreenBuffer::draw()
{
    for (int y = 0; y < 10; y++) {
        std::cout << "\n";
        for (int x = 0; x < 20; x++) {
            std::cout << m_map[y][x];
        }
    }

    std::cout << "\n";
}

void ScreenBuffer::draw_pixel(int x, int y, char symbol)
{
    m_map[y][x] = symbol;
}

void ScreenBuffer::clear_buffer()
{
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            m_map[y][x] = '.';
        }
    }
}
