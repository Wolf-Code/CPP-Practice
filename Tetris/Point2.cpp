#include "Point2.h"

CPPEngine::Point2 CPPEngine::Point2::operator+( Point2 point ) const
{
    point.X += this->X;
    point.Y += this->Y;

    return point;
}

CPPEngine::Point2 CPPEngine::Point2::operator-( Point2 point ) const
{
    point.X -= this->X;
    point.Y -= this->Y;

    return point;
}

CPPEngine::Point2& CPPEngine::Point2::operator+=( const Point2& point )
{
    this->X += point.X;
    this->Y += point.Y;

    return *this;
}