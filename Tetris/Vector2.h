#pragma once
#ifndef __VECTOR2_H__
#define __VECTOR2_H__

namespace CPPEngine
{
    /// <summary> A 2D vector. </summary>
    struct Vector2
    {
        Vector2( const float x = 0, const float y = 0 ) : X( x ), Y( y ) {};

        /// <summary> Addition operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector2 operator+( Vector2 vector ) const
        {
            vector.X += this->X;
            vector.Y += this->Y;

            return vector;
        }

        /// <summary> Subtraction operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector2 operator-( Vector2 vector ) const
        {
            vector.X -= this->X;
            vector.Y -= this->Y;

            return vector;
        }

        /// <summary> Addition assignment operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector2& operator+=( const Vector2& vector )
        {
            this->X += vector.X;
            this->Y += vector.Y;

            return *this;
        }

        /// <summary> Subtraction assignment operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector2& operator-=( const Vector2& vector )
        {
            this->X -= vector.X;
            this->Y -= vector.Y;

            return *this;
        }

        /// <summary> The X coordinate. </summary>
        float X;

        /// <summary> The Y coordinate. </summary>
        float Y;
    };
}
#endif

