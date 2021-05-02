#pragma once

const float PI = 3.14159265359f;

inline float degToRad(float degree)
{
    return (degree * (PI / 180));
}

class Vector2
{
public:
    float x;
    float y;

    Vector2();
    Vector2(float vx, float vy);
    Vector2(Vector2 const &other);
    
    Vector2 normalized();
};

Vector2 operator + (Vector2 const &left, Vector2 const &right);

Vector2 operator - (Vector2 const &left, Vector2 const &right);

Vector2 operator * (float left, Vector2 const &right);

float distance(const Vector2& first, const Vector2& second);

float dotProduct(const Vector2& first, const Vector2& second);