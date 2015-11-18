#pragma once
#ifndef __OBJECTBASE_H__
#define __OBJECTBASE_H__

#include "HitResult.h"
#include "Ray.h"

class ObjectBase
{
public:
    virtual HitResult GetCollision( const Ray& ray ) const = 0;
    virtual ~ObjectBase( ) {};
};
#endif
