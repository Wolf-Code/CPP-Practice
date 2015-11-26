#include "Vector2.h"

CPPEngine::Vector2 CPPEngine::Vector2::operator+( Vector2 vector ) const
{
    vector.X += this->X;
    vector.Y += this->Y;

    return vector;
}


CPPEngine::Vector2 CPPEngine::Vector2::operator-( Vector2 vector ) const
{
    vector.X -= this->X;
    vector.Y -= this->Y;

    return vector;
}

CPPEngine::Vector2& CPPEngine::Vector2::operator+=( const Vector2& vector )
{
    this->X += vector.X;
    this->Y += vector.Y;

    return *this;
}

CPPEngine::Vector2& CPPEngine::Vector2::operator-=( const Vector2& vector )
{
    this->X -= vector.X;
    this->Y -= vector.Y;

    return *this;
}

