#include "SphereObject.h"

HitResult SphereObject::GetCollision( const Ray& ray ) const
{
    HitResult Res = HitResult( );
    
    // Calculate ray start's offset from the sphere center
    CPPEngine::Vector3 p = ray.Start - this->Center;

    float rSquared = this->Radius * this->Radius;
    float p_d = p.Dot( ray.Direction );

    // The sphere is behind the start point.
    if ( p_d < 0 )
        return Res;

    // The sphere contains the ray's start point.
    if( p.LengthSquared( ) < rSquared )
    {
        Res.Hit = true;
        Res.Position = ray.Start;

        return Res;
    }

    // Flatten p into the plane passing through c perpendicular to the ray.
    // This gives the closest approach of the ray to the center.
    CPPEngine::Vector3 a = p - ray.Direction * p_d;
    float aSquared = a.LengthSquared( );

    // Closest approach is outside the sphere.
    if ( aSquared > rSquared )
        return Res;

    // Calculate distance from plane where ray enters/exits the sphere.    
    float h = sqrt( rSquared - aSquared );

    // Calculate intersection point relative to sphere center.
    CPPEngine::Vector3 i = a - h * ray.Direction;

    CPPEngine::Vector3 intersection = this->Center + i;
    CPPEngine::Vector3 normal = i / this->Radius;
    // We've taken a shortcut here to avoid a second square root.
    // Note numerical errors can make the normal have length slightly different from 1.
    // If you need higher precision, you may need to perform a conventional normalization.

    Res.Position = intersection;
    Res.Normal = normal;
    Res.DistanceSquared = ( intersection - ray.Start ).LengthSquared( );
    Res.Object = this;
    Res.Hit = true;
    return Res;
}