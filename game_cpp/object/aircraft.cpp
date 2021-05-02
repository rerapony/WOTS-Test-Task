#include "aircraft.hpp"

#include "../common.hpp"

#include <cassert>
#include <cstdlib>
#include <cmath>

Aircraft::Aircraft()
{
    maxAngularSpeed = params::aircraft::ANGULAR_SPEED;
    maxLinearSpeed = params::aircraft::LINEAR_SPEED;
    isFlying = false;
}

void Aircraft::init()
{
    assert(!mesh);
    mesh = scene::createAircraftMesh();
    position = Vector2(0.f, 0.f);
    angle = 0.f;
    isFlying = true;
    isReturning = false;
    time = 0;
    randomTurnDir = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
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
    angle = target->getAngle();

    Vector2 targetPos = target->getPosition();

    if (!isReturning) {
        targetPos = targetPos + randomTurnDir * params::aircraft::TARGET_RADIUS * Vector2(targetPos.y, -targetPos.x).normalized();
    }

    Vector2 targetVector = targetPos - position;

    // calculating cross product in 3D z component to get turning direction
    Vector2 dir_vector = Vector2(std::cos(angle), std::sin(angle));
    float cross_z = dir_vector.x * targetVector.y - dir_vector.y * targetVector.x;

    float turnValue = cross_z > 0 ? 1 : -1;
    //if (Vector3.Dot(targetVector, transform.right) > 0)
    //{
    //    turnValue *= Mathf.Clamp01(Mathf.Abs(cross));
    //}

    angle = angle + turnValue * maxAngularSpeed * dt;
    position = position + maxLinearSpeed * dt * Vector2(std::cos(angle), std::sin(angle));

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
    return isReturning;
}

void Aircraft::setIsReturning(bool b) {
    isReturning = b;
}

float Aircraft::getTime()
{
    return time;
}
