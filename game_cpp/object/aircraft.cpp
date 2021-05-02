#include "aircraft.hpp"

#include "../common.hpp"

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

Aircraft::Aircraft() : 
    target(nullptr),
    isFlying(false),
    isLanding(false),
    time(0),
    linearSpeed(0)
{
    maxAngularSpeed = params::aircraft::ANGULAR_SPEED;
    maxLinearSpeed = params::aircraft::LINEAR_SPEED;
}

void Aircraft::init()
{
    assert(!mesh);
    mesh = scene::createAircraftMesh();
    isFlying = true;
    isLanding = false;
    time = 0;
    linearSpeed = 0;

    float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    randomTurnDir = (random > 0.5f) ? 1 : -1;

    randomAngularMult = 0.8f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.2f - 0.8f)));
}

void Aircraft::deinit()
{
    scene::destroyMesh(mesh);
    mesh = nullptr;
    target = nullptr;
    isFlying = false;
}

void Aircraft::update(float dt)
{
    assert(target != nullptr);
    Vector2 targetPos = target->getPosition();
    Vector2 targetVector = targetPos - position;

    // calculating cross product in 3D z component to get turning direction
    Vector2 forwardVector = getForwardVector();
    
    float cross_z = forwardVector.x * targetVector.y - forwardVector.y * targetVector.x;
    float turnValue = cross_z > 0 ? 1 : -1;

    if (linearSpeed < maxLinearSpeed) {
        linearSpeed += params::aircraft::LINEAR_ACCELERATION * dt;
    }
    else {
        // we can't change angle while not on full speed
        angle = angle + randomAngularMult * turnValue * maxAngularSpeed * dt;
    }

    position = position + linearSpeed * dt * getForwardVector();

    scene::placeMesh(mesh, position.x, position.y, angle);
    time += dt;
}

void Aircraft::setTarget(PhysicalEntity* entity) {
    target = entity;
}

bool Aircraft::getIsFlying()
{
    return isFlying;
}

bool Aircraft::getIsReturning() {
    return isLanding;
}

void Aircraft::setIsReturning(bool b) {
    isLanding = b;
}

float Aircraft::getTime()
{
    return time;
}
