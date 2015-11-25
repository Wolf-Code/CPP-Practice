#define _USE_MATH_DEFINES
#include <math.h>
#include "MathHelper.h"

#define M_PI_DIVIDED_BY_180 M_PI / 180.0f;
#define M_180_DIVIDED_BY_PI 180.0f / M_PI;



float MathHelper::Sin(float angle, bool radians)
{
    if ( !radians )
        angle = DegreesToRadians( angle );

    return float( sin( angle ) );
}

float MathHelper::Cos(float angle, bool radians)
{
    if ( !radians )
        angle = DegreesToRadians( angle );

    return float( cos( angle ) );
}

float MathHelper::DegreesToRadians( const float angle )
{
    return angle * M_PI_DIVIDED_BY_180;
}

float MathHelper::RadiansToDegrees( const float angle )
{
    return angle * M_180_DIVIDED_BY_PI;
}