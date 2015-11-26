#include "Camera.h"
#include "Ray.h"
#include "MathHelper.h"
#include "Vector2.h"

Ray CPPEngine::Camera::GetRay( const float x, const float y )
{
    Vector3 Dir = this->Angle.GetForward( ) * FOVDivided +
        this->Angle.GetRight( ) * ( x / this->Width - 0.5f ) *
        this->AspectRatio -
        this->Angle.GetUp( ) * ( y / this->Height - 0.5f );

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

void CPPEngine::Camera::SetResolution( const float width, const float height )
{
    this->Width = width;
    this->Height = height;
    this->AspectRatio = this->Width / this->Height;
}