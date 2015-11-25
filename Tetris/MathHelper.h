#pragma once
#ifndef __MATHHELPER_H__
#define __MATHHELPER_H__

class MathHelper
{
public:
    static float Sin( float angle, bool radians = true );
    static float Cos( float angle, bool radians = true );
    static float DegreesToRadians( const float angle );
    static float RadiansToDegrees( const float angle );
};

#endif