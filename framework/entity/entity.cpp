#include "entity.hpp"

#include <cmath>

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

Vector2 PhysicalEntity::getForwardVector()
{
    return Vector2(std::cos(angle), std::sin(angle));

}
