#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Angle.h"
#include "Vector3.h"

struct Ray;

namespace CPPEngine
{
    class Camera
    {
    public:
        Camera( ) : Angle( CPPEngine::Angle( ) ), Position( Vector3( ) ), FOV( 90 ), FOVDivided( 1 ), Width( 0 ), Height( 0 ), AspectRatio( 1 ) {};
        Ray GetRay( const float x, const float y );

        void SetFOV( float fov, bool radians = true );
        void SetResolution( const float width, const float height );
        void SetPosition( const Vector3& vector );

    private:
        Angle Angle;
        Vector3 Position;
        float FOV;
        float FOVDivided;
       
        float Width;
        float Height;

        float AspectRatio;
    };
}
#endif