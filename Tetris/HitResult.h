#pragma once
#ifndef __HITRESULT_H__
#define __HITRESULT_H__
#include "Vector3.h"

class ObjectBase;

struct HitResult
{
public:
    HitResult( ) : Hit( false ), Position( CPPEngine::Vector3( ) ), Normal( CPPEngine::Vector3( ) ), DistanceSquared( 0 ), Object( nullptr ), IsDistanceSet( false ), RealDistance( 0 ) {};

    /// <summary> Gets the distance. </summary>
    /// <returns> The distance. </returns>
    float Distance( ) const;

    /// <summary>Sets the distance if it's known beforehand, will skip a square root if requesting the distance later.</summary>
    void SetDistance( const float distance );

    bool Hit;
    CPPEngine::Vector3 Position;
    CPPEngine::Vector3 Normal;
    float DistanceSquared;
    const ObjectBase* Object;

private:
    bool IsDistanceSet;
    float RealDistance;
};

#endif

