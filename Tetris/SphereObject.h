#pragma once
#ifndef __SPHEREOBJECT_H__
#define __SPHEREOBJECT_H__
#include "ObjectBase.h"
#include "Vector3.h"

class SphereObject : public ObjectBase
{
public:
    SphereObject( const CPPEngine::Vector3& center, const float radius ) : Center( center ), Radius( radius ), RadiusSquared( radius * radius ) {};
    ~SphereObject( ) {};

    HitResult GetCollision( const Ray& ray ) const override;

    CPPEngine::Vector3 Center;
    float Radius;

private:
    float RadiusSquared;
};
#endif