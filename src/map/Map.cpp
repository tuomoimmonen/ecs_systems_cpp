#include "Map.h"
#include <iostream>

Map::Map()
{
    std::cout << "Map constructor called\n";
    create_map();

    //print();
}

Map::~Map()
{
    std::cout << "\033[31m" << "Map destructor called" << "\033[0m\n";
}

bool Map::is_inside(int x, int y) const
{
    if (x < 20 && y < 10)
    {
        return m_boundaries[y][x] != 0;
    }
    else {
        return false;
    }
}

void Map::create_map()
{
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            if (y == 0 || y == 9) {
                m_boundaries[y][x] = 0;
            }
            else if (x == 0 || x == 19) {
                m_boundaries[y][x] = 0;
            }
            else {
                m_boundaries[y][x] = 1;
            }
        }
    }
}

void Map::print()
{
    for (int y = 0; y < 10; y++) {
        std::cout << "\n";
        for (int x = 0; x < 20; x++) {
            std::cout << m_boundaries[y][x];
        }
    }
}
