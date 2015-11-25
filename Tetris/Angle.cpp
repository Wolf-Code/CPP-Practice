#include "Angle.h"
#include "Vector3.h"
#include <math.h>
const float Mod = 360.0f;

void CPPEngine::Angle::SetPitch( float pitch )
{
    this->Pitch = fmodf( pitch, Mod );
    ShouldUpdate = true;
}

void CPPEngine::Angle::SetYaw( const float yaw )
{
    this->Yaw = fmodf( yaw, Mod );
    ShouldUpdate = true;
}

void CPPEngine::Angle::SetRoll( const float roll )
{
    this->Roll = fmodf( roll, Mod );
    ShouldUpdate = true;
}

void CPPEngine::Angle::SetAngle(const float pitch, const float yaw, const float roll)
{
    this->SetPitch( pitch );
    this->SetYaw( yaw );
    this->SetRoll( roll );
}

void CPPEngine::Angle::AddPitch( const float pitch )
{
    this->SetPitch( this->Pitch + pitch );
}

void CPPEngine::Angle::AddYaw( const float yaw )
{
    this->SetYaw( this->Yaw + yaw );
}

void CPPEngine::Angle::AddRoll( const float roll )
{
    this->SetRoll( this->Roll + roll );
}

float CPPEngine::Angle::GetPitch( ) const
{
    return this->Pitch;
}

float CPPEngine::Angle::GetYaw( ) const
{
    return this->Yaw;
}

float CPPEngine::Angle::GetRoll( ) const
{
    return this->Roll;
}

CPPEngine::Vector3 CPPEngine::Angle::GetForward( )
{
    CheckForUpdateMatrix( );

    return this->Rotation.Forward( );
}

CPPEngine::Vector3 CPPEngine::Angle::GetRight( )
{
    CheckForUpdateMatrix( );

    return this->Rotation.Right( );
}

CPPEngine::Vector3 CPPEngine::Angle::GetUp( )
{
    CheckForUpdateMatrix( );

    return this->Rotation.Up( );
}

void CPPEngine::Angle::UpdateMatrix( )
{
    this->Rotation = Matrix4x4::CreateRotation( this->Pitch, this->Yaw, this->Roll );
}

void CPPEngine::Angle::CheckForUpdateMatrix( )
{
    if ( ShouldUpdate )
        this->UpdateMatrix( );
}