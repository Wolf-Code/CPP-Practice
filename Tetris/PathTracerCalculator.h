#pragma once
#ifndef __PATHTRACERCALCULATOR_H__
#define __PATHTRACERCALCULATOR_H__

namespace CPPEngine
{
    struct Vector3;
    struct Color;
}

class Scene;
struct HitResult;
struct Ray;

class PathTracerCalculator
{
public:
    static HitResult GetClosestHit( const Scene& scene, const Ray& ray );
    static Ray GetNextRay( const Ray& ray, const HitResult& prevhit );

    static CPPEngine::Color GetTraceColor( const Scene& scene, Ray ray );
    static CPPEngine::Vector3 GetRandomDirectionInHemisphere( const CPPEngine::Vector3& normal );

    static float GetRandomFloat( );
    static float GetRandomFloatOneMinOne( );
};

#endif