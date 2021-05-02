#include "target.hpp"

Target::Target()
{
    mesh = nullptr;
}

void Target::init()
{
    position = Vector2(0.f, 0.f);
    angle = 0.f;
}

void Target::deinit()
{
    position = Vector2(0.f, 0.f);
    angle = 0.f;
}

void Target::update(float dt)
{
    scene::placeGoalMarker(position.x, position.y);
}