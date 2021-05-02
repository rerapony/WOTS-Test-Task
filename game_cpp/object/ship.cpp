#include "ship.hpp"

#include <cassert>
#include <cmath>

#include "../../framework/game.hpp"
#include "../common.hpp"

Ship::Ship()
{
    maxLinearSpeed = params::ship::LINEAR_SPEED;
    maxAngularSpeed = params::ship::ANGULAR_SPEED;
}


void Ship::init()
{
    assert(!mesh);
    mesh = scene::createShipMesh();
    position = Vector2(0.f, 0.f);
    angle = 0.f;
    for (bool &key : input) {
        key = false;
    }
}


void Ship::deinit()
{
    scene::destroyMesh(mesh);
    mesh = nullptr;
}


void Ship::update(float dt)
{
    float linearSpeed = 0.f;
    float angularSpeed = 0.f;

    if (input[game::KEY_FORWARD])
    {
        linearSpeed = maxLinearSpeed;
    }
    else if (input[game::KEY_BACKWARD])
    {
        linearSpeed = -maxLinearSpeed;
    }

    if (input[game::KEY_LEFT] && linearSpeed != 0.f)
    {
        angularSpeed = maxAngularSpeed;
    }
    else if (input[game::KEY_RIGHT] && linearSpeed != 0.f)
    {
        angularSpeed = -maxAngularSpeed;
    }

    angle = angle + angularSpeed * dt;
    position = position + linearSpeed * dt * Vector2(std::cos(angle), std::sin(angle));
    scene::placeMesh(mesh, position.x, position.y, angle);
}


void Ship::keyPressed(int key)
{
    assert(key >= 0 && key < game::KEY_COUNT);
    input[key] = true;
}


void Ship::keyReleased(int key)
{
    assert(key >= 0 && key < game::KEY_COUNT);
    input[key] = false;
}

void Ship::mouseClicked(Vector2 worldPosition, bool isLeftButton)
{
}
