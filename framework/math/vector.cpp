#include "vector.hpp"

#include <cmath>

Vector2::Vector2() :
    x(0.f),
    y(0.f)
{
}


Vector2::Vector2(float vx, float vy) :
    x(vx),
    y(vy)
{
}


Vector2::Vector2(Vector2 const &other) :
    x(other.x),
    y(other.y)
{
}

Vector2 Vector2::normalized()
{
    float length = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    return Vector2(x / length, y / length);
}


Vector2 operator + (Vector2 const &left, Vector2 const &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}

Vector2 operator - (Vector2 const &left, Vector2 const &right) {
    return Vector2(left.x - right.x, left.y - right.y);
}


Vector2 operator * (float left, Vector2 const &right)
{
    return Vector2(left * right.x, left * right.y);
}

float distance(const Vector2 & first, const Vector2 & second)
{
    return std::sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2));
}