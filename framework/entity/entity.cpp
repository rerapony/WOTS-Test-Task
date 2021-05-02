#include "entity.hpp"

PhysicalEntity::PhysicalEntity(): mesh(nullptr), position(0, 0), angle(0)
{
}

void PhysicalEntity::setPosition(const Vector2& p) {
    position = p;
}

void PhysicalEntity::setAngle(const float a) {
    angle = a;
}

Vector2 PhysicalEntity::getPosition()
{
    return position;
}

float PhysicalEntity::getAngle()
{
    return angle;
}