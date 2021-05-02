#pragma once

#include "../../framework/entity/entity.hpp"

class Ship : public ControlledEntity
{
public:
    Ship();

    virtual void init() override;
    virtual void deinit() override;
    virtual void update(float dt) override;
    virtual void keyPressed(int key) override;
    virtual void keyReleased(int key) override;
};

