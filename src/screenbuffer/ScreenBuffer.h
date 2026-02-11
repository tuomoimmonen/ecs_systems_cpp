#pragma once

class ScreenBuffer
{
public:
    ScreenBuffer();
    ~ScreenBuffer();

    void draw();
    void draw_pixel(int x, int y, char symbol);
    void clear_buffer();

private:
    char m_map[10][20];
};