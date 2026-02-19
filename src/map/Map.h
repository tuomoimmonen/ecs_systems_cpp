#pragma once

class Map
{
public:
    Map();
    ~Map();

    bool is_inside(int x, int y) const;

private:
    void create_map();
    void print();
    
private:
    int m_boundaries[10][20];
};