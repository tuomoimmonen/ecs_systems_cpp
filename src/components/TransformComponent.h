#pragma once
#include "Component.h"

class TransformComponent : public Component
{
public:
    TransformComponent(int x_pos = 0, int y_pos = 0);
    ~TransformComponent();

    virtual void update() override;
    virtual void print() override;

    void set_x(int new_x) { x_position += new_x; }
    void set_y(int new_y) { y_position += new_y; }

    const int get_x() const { return x_position; }
    const int get_y() const { return y_position; }
    
private:
    int x_position = 0;
    int y_position = 0;

};