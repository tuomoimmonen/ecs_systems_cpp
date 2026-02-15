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

private:
    int x_direction = 0;
    int y_direction = 0;

};