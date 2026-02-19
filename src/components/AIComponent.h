#pragma once
#include "Component.h"

class AIComponent : public Component
{
public:
    AIComponent();
    ~AIComponent();

    virtual void update() override;
    virtual void print() override;

    int get_x() const { return x_direction; }
    int get_y() const { return y_direction; }
    
private:
    int x_direction = 0;
    int y_direction = 0;

};