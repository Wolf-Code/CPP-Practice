#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Angle.h"
#include "Vector3.h"
#include "Vector2.h"

struct Ray;

namespace CPPEngine
{
    class Camera
    {
    public:
        Camera( ) : Angle( CPPEngine::Angle( ) ), Position( Vector3( ) ), FOV( 90 ), FOVDivided( 1 ), Resolution( Vector2( ) ), AspectRatio( 1 ) {};
        Ray GetRay( const float x, const float y );

        void SetFOV( float fov, bool radians = true );
        void SetResolution( Vector2 resolution );

    private:
        Angle Angle;
        Vector3 Position;
        float FOV;
        float FOVDivided;
        Vector2 Resolution;
        float AspectRatio;
    };
}
#endif