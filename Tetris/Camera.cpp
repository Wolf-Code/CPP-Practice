#include "Camera.h"
#include "Ray.h"
#include "MathHelper.h"

Ray CPPEngine::Camera::GetRay( const float x, const float y )
{
    Vector3 Dir = this->Angle.GetForward( ) * FOVDivided +
        this->Angle.GetRight( ) * ( x / this->Resolution.X - 0.5f ) *
        this->AspectRatio -
        this->Angle.GetUp( ) * ( y / this->Resolution.Y - 0.5f );

    Dir.Normalize( );

    return Ray( this->Position, Dir );
}

void CPPEngine::Camera::SetFOV( float fov, bool radians )
{
    if ( !radians )
        fov = MathHelper::DegreesToRadians( fov );

    this->FOV = fov;
    this->FOVDivided = 0.5f / tanf( fov / 2.0f );
}

void CPPEngine::Camera::SetResolution( Vector2 resolution )
{
    this->Resolution = resolution;
    this->AspectRatio = resolution.X / resolution.Y;
}