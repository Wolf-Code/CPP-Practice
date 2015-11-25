#pragma once
#ifndef __HITRESULT_H__
#define __HITRESULT_H__
#include "Vector3.h"

class ObjectBase;

struct HitResult
{
public:
    HitResult( ) : Hit( false ), Position(CPPEngine::Vector3( ) ), Normal( CPPEngine::Vector3( ) ), DistanceSquared( 0 ), Object( nullptr ) {};
    /// <summary> Gets the distance. </summary>
    /// <returns> The distance. </returns>
    float Distance( ) const { return sqrt( this->DistanceSquared ); };

    bool Hit;
    CPPEngine::Vector3 Position;
    CPPEngine::Vector3 Normal;
    float DistanceSquared;
    const ObjectBase* Object;
};

#endif

