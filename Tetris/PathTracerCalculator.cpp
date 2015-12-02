#include "PathTracerCalculator.h"
#include "ObjectBase.h"
#include "Scene.h"
#include "Ray.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

HitResult PathTracerCalculator::GetClosestHit( const Scene& scene, const Ray& ray )
{
    const std::vector<ObjectBase*>& objects = scene.GetObjects( );
    HitResult closestRes = HitResult( );

    if ( objects.size( ) <= 0 )
        return closestRes;

    for ( std::vector<ObjectBase*>::size_type i = 0; i < objects.size( ); i++ )
    {
        const ObjectBase* obj = objects[ i ];
        const HitResult res = obj->GetCollision( ray );
        if ( !res.Hit )
            continue;

        if ( res.DistanceSquared != closestRes.DistanceSquared || !closestRes.Hit )
        {
            closestRes = res;
            //std::cout << res.Distance( ) << std::endl;
        }
    }

    return closestRes;
}

Ray PathTracerCalculator::GetNextRay( const Ray& ray, const HitResult& prevhit )
{
    return Ray( prevhit.Position + prevhit.Normal * 0.05f, GetRandomDirectionInHemisphere( prevhit.Normal ), ray.Bounces - 1 );
}

CPPEngine::Color PathTracerCalculator::GetTraceColor( const Scene& scene, Ray ray )
{
    CPPEngine::Color result = CPPEngine::Color::Black( );
    CPPEngine::Color accumulation = CPPEngine::Color::White( );

    while ( ray.Bounces > 0 )
    {
        const HitResult closest = GetClosestHit( scene, ray );
        
        if ( !closest.Hit )
            return CPPEngine::Color::Black( );

        //return CPPEngine::Color( closest.Distance( ) / 22.0f );
        //return closest.Object->SurfaceMaterial.ColorDiffuse;// CPPEngine::Color( closest.Normal.X, closest.Normal.Y, closest.Normal.Z );
        
        result += accumulation * closest.Object->SurfaceMaterial.ColorEmission;
        accumulation *= closest.Object->SurfaceMaterial.ColorDiffuse;

        Ray newRay = GetNextRay( ray, closest );
        accumulation *= closest.Normal.Dot( newRay.Direction );
        accumulation *= 2;

        ray = newRay;
    }

    return result;
}

CPPEngine::Vector3 PathTracerCalculator::GetRandomDirectionInHemisphere( const CPPEngine::Vector3& normal )
{
    float r1 = 2 * M_PI * GetRandomFloat( );
    float r2 = GetRandomFloat( );
    float r2s = sqrt( r2 );

    CPPEngine::Vector3 w = normal;
    CPPEngine::Vector3 u = ( fabs( w.X ) > .1f ? CPPEngine::Vector3( 0, 1, 0 ) : CPPEngine::Vector3( 1, 0, 0 ) ).Cross( w ).Normalized( );
    CPPEngine::Vector3 v = w.Cross( u );
    CPPEngine::Vector3 d = ( u * cos( r1 ) * r2s + v * sin( r1 ) * r2s + w * sqrt( 1 - r2 ) ).Normalized( );

    return d;
}

float PathTracerCalculator::GetRandomFloat( )
{
    return rand( ) / float( RAND_MAX );
}

float PathTracerCalculator::GetRandomFloatOneMinOne( )
{
    return GetRandomFloat( ) * 2.0f - 1.0f;
}
