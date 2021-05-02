#pragma once

#include "../../framework/entity/entity.hpp"

class Aircraft : public MoveableEntity
{
public:
    Aircraft();

    virtual void init() override;
    virtual void deinit() override;
    virtual void update(float dt) override;
    
    void setTarget(PhysicalEntity* entity);

    bool getIsFlying();

    bool getIsReturning();
    void setIsReturning(const bool);

    float getTime();

private:
    PhysicalEntity* target;
    bool isFlying;
    bool isLanding;
    float time;
    float linearSpeed;
    int randomTurnDir;
    float randomAngularMult;
};

