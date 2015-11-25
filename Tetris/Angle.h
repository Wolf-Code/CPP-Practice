#pragma once
#ifndef __ANGLE_H__
#define __ANGLE_H__
#include "Matrix4x4.h"

struct Vector3;

namespace CPPEngine
{
    struct Vector3;

    /// <summary>
    /// A 3D angle consisting of pitch, yaw and roll.
    /// </summary>
    struct Angle
    {
        explicit Angle( const float pitch = 0, const float yaw = 0, const float roll = 0 ) : Rotation( Matrix4x4::Zero( ) ), ShouldUpdate( false )
        {
            this->SetAngle( pitch, yaw, roll );
        };

        /// <summary>
        /// Sets the pitch.
        /// </summary>
        /// <param name="pitch"> The pitch. </param>
        void SetPitch( const float pitch );

        /// <summary>
        /// Sets the yaw.
        /// </summary>
        /// <param name="yaw"> The yaw. </param>
        void SetYaw( const float yaw );

        /// <summary>
        /// Sets the roll.
        /// </summary>
        /// <param name="roll"> The roll. </param>
        void SetRoll( const float roll );

        /// <summary>
        /// Sets the angle.
        /// </summary>
        /// <param name="pitch"> The pitch. </param>
        /// <param name="yaw">   The yaw. </param>
        /// <param name="roll">  The roll. </param>
        void SetAngle( const float pitch, const float yaw, const float roll );

        /// <summary>
        /// Adds pitch to the current pitch.
        /// </summary>
        /// <param name="pitch"> The pitch. </param>
        void AddPitch( const float pitch );

        /// <summary>
        /// Adds yaw to the current yaw.
        /// </summary>
        /// <param name="yaw"> The yaw. </param>
        void AddYaw( const float yaw );

        /// <summary>
        /// Adds roll to the current roll.
        /// </summary>
        /// <param name="roll"> The roll. </param>
        void AddRoll( const float roll );

        /// <summary>
        /// Gets the pitch.
        /// </summary>
        /// <returns> The pitch. </returns>
        float GetPitch( ) const;

        /// <summary>
        /// Gets the yaw.
        /// </summary>
        /// <returns> The yaw. </returns>
        float GetYaw( ) const;

        /// <summary>
        /// Gets the roll.
        /// </summary>
        /// <returns> The roll. </returns>
        float GetRoll( ) const;

        /// <summary>
        /// Gets the forward vector of this angle.
        /// </summary>
        /// <returns>
        /// The forward vector.
        /// </returns>
        Vector3 GetForward( );

        /// <summary>
        /// Gets the right vector of this angle.
        /// </summary>
        /// <returns>
        /// The right vector.
        /// </returns>
        Vector3 GetRight( );

        /// <summary>
        /// Gets the up vector of this angle.
        /// </summary>
        /// <returns>
        /// The up vector.
        /// </returns>
        Vector3 GetUp( );

    private:
        void UpdateMatrix( );
        void CheckForUpdateMatrix( );
        Matrix4x4 Rotation;
        float Pitch;
        float Yaw;
        float Roll;
        bool ShouldUpdate;
    };
}
#endif
