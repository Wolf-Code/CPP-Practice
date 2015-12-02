#include "SphereObject.h"
#include "Ray.h"
#include "PathTracerSettings.h"

bool solveQuadratic( const float &a, const float &b, const float &c, float &x0, float &x1 )
{
    float discr = b * b - 4 * a * c;

    if ( discr < 0 ) return false;

    if ( discr == 0 ) x0 = x1 = -0.5 * b / a;

    else
    {
        float q = ( b > 0 ) ?
            -0.5 * ( b + sqrt( discr ) ) :
            -0.5 * ( b - sqrt( discr ) );
        x0 = q / a;
        x1 = c / q;
    }
    if ( x0 > x1 ) std::swap( x0, x1 );

    return true;
}

HitResult SphereObject::GetCollision(const Ray& ray) const
{
    float t0, t1; // solutions for t if the ray intersects 
#if 1
                  // geometric solution
    CPPEngine::Vector3 L = this->Center - ray.Start;
    float tca = L.Dot( ray.Direction );
    if ( tca < 0 ) return HitResult( );

    float d2 = L.LengthSquared( ) - tca * tca;
    if ( d2 > this->RadiusSquared ) return HitResult( );

    float thc = sqrt( this->RadiusSquared - d2 );
    t0 = tca - thc;
    t1 = tca + thc;
#else 
                  // analytic solution
    CPPEngine::Vector3 L = ray.Start - this->Center;
    float a = ray.Direction.LengthSquared( );
    float b = 2 * ray.Direction.Dot( L );
    float c = L.LengthSquared( ) - this->RadiusSquared;
    if ( !solveQuadratic( a, b, c, t0, t1 ) ) return HitResult( );
#endif 

    if ( t0 > t1 ) std::swap( t0, t1 );

    if ( t0 < 0 )
    {
        t0 = t1; // if t0 is negative, let's use t1 instead 
        if ( t0 < 0 ) return HitResult( ); // both t0 and t1 are negative 
    }

    HitResult res;
    res.SetDistance( t0 );
    res.Object = this;
    res.Position = ray.Start + ray.Direction * t0;
    res.Normal = ( res.Position - this->Center ).Normalized( );
    res.Hit = true;

    return res;
}


/*
HitResult SphereObject::GetCollision( const Ray& ray ) const
{
    HitResult Res = HitResult( );

    // Calculate ray start's offset from the sphere center
    CPPEngine::Vector3 p = ray.Start - this->Center;

    float p_d = p.Dot( ray.Direction );
    // The sphere is behind the start point.
    if ( p_d < 0 )
        return Res;

    float rSquared = this->Radius * this->Radius;

    // The sphere contains the ray's start point.
    if ( p.LengthSquared( ) < rSquared )
        return Res;

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
    CPPEngine::Vector3 i = a - ray.Direction * h;

    CPPEngine::Vector3 intersection = this->Center + i;
#if USESQUAREROOTFORNORMAL
    CPPEngine::Vector3 normal = i.Normalized( );
#else
    CPPEngine::Vector3 normal =  i / this->Radius;
#endif

    Res.Position = intersection;
    Res.Normal = normal;
    Res.DistanceSquared = ( intersection - ray.Start ).LengthSquared( );
    Res.Object = this;
    Res.Hit = true;

    return Res;
}
*/