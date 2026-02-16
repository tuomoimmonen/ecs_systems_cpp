#pragma once
#include "components/Component.h"

class InputComponent : public Component
{
public:
    InputComponent();
    ~InputComponent();

    virtual void update() override;
    virtual void print() override;

    void set_direction(int x_dir, int y_dir);

    int get_x_direction() const { return x_direction; }
    int get_y_direction() const { return y_direction; }

private:
    int x_direction = 0;
    int y_direction = 0;

};