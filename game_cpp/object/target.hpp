#pragma once

#include "../../framework/entity/entity.hpp"

class Target :
    public PhysicalEntity
{
public:
    Target();
    virtual void init() override;
    virtual void deinit() override;
    virtual void update(float dt) override;
};

