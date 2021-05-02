#pragma once

#include "../scene.hpp"
#include "../game.hpp"
#include "../math/vector.hpp"

//-------------------------------------------------------
//	Basic Entity class
//-------------------------------------------------------

class Entity {
public:
    Entity() = default;
    virtual void init() = 0;
    virtual void deinit() = 0;
    virtual void update(float dt) = 0;
};

class PhysicalEntity: public Entity {
public:
    PhysicalEntity() = default;
    void setPosition(const Vector2& p);
    void setAngle(const float a);
    Vector2 getPosition();
    float getAngle();
    Vector2 getForwardVector();

protected:
    scene::Mesh *mesh;
    Vector2 position;
    float angle;
};

class MoveableEntity : public PhysicalEntity {
public:
    MoveableEntity() = default;

protected:
    float maxLinearSpeed;
    float maxAngularSpeed;
};

class ControlledEntity: public MoveableEntity {
public:
    ControlledEntity() = default;
    virtual void keyPressed(int key) = 0;
    virtual void keyReleased(int key) = 0;

protected:
    bool input[game::KEY_COUNT];
};