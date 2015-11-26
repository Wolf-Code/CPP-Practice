#pragma once
#ifndef __OBJECTBASE_H__
#define __OBJECTBASE_H__

#include "HitResult.h"
#include "Ray.h"
#include "Material.h"


class ObjectBase
{
public:
    ObjectBase( ) :SurfaceMaterial( Material( ) ) {};
    virtual ~ObjectBase( ) {};

    virtual HitResult GetCollision( const Ray& ray ) const = 0;

    Material SurfaceMaterial;
};
#endif
