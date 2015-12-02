#include "Camera.h"
#include "Ray.h"
#include "MathHelper.h"
#include "PathTracerCalculator.h"
#include "PathTracerSettings.h"

Ray CPPEngine::Camera::GetRay( const float x, const float y )
{
    const float randx = x + PathTracerCalculator::GetRandomFloatOneMinOne( ) * 0.5f;
    const float randy = y + PathTracerCalculator::GetRandomFloatOneMinOne( ) * 0.5f;

    const float pixelXNDC = ( randx + 0.5f ) / this->Width;
    const float pixelYNDC = ( randy + 0.5f ) / this->Height;

    const float pixelScreenX = 2 * pixelXNDC - 1;
    const float pixelScreenY = 1 - 2 * pixelYNDC;

    Vector3 Dir = this->Angle.GetForward( ) * FOVDivided +
        this->Angle.GetRight( ) * pixelScreenX *
        this->AspectRatio -
        this->Angle.GetUp( ) * pixelScreenY;

    Dir.Normalize( );

    return Ray( this->Position, Dir, MAXBOUNCES );
}

void CPPEngine::Camera::SetFOV( float fov, bool radians )
{
    if ( !radians )
        fov = MathHelper::DegreesToRadians( fov );

    this->FOV = fov;
    this->FOVDivided = 0.5f / tan( fov / 2.0f );
}

void CPPEngine::Camera::SetResolution( const float width, const float height )
{
    this->Width = width;
    this->Height = height;
    this->AspectRatio = this->Width / this->Height;
}

void CPPEngine::Camera::SetPosition(const Vector3& vector)
{
    this->Position = vector;
}
