#pragma once
#ifndef __SPHEREOBJECT_H__
#define __SPHEREOBJECT_H__
#include "ObjectBase.h"
#include "Vector3.h"

class SphereObject : public ObjectBase
{
public:
    SphereObject( const Vector3& center, const float radius ) : Center( center ), Radius( radius ) {};
    ~SphereObject( ) {};

    HitResult GetCollision( const Ray& ray ) const override;

    Vector3 Center;
    float Radius;
};
#endif