#pragma once
#ifndef __VECTOR3_H__
#define __VECTOR3_H__
#include "stdafx.h"


namespace CPPEngine
{
    struct Color;

    struct Vector3
    {
        /// <summary> Constructor. </summary>
        /// <param name="x"> The x coordinate. </param>
        /// <param name="y"> The y coordinate. </param>
        /// <param name="z"> The z coordinate. </param>
        Vector3( float x = 0, float y = 0, float z = 0 ) : X( x ), Y( y ), Z( z ) {};

        /// <summary> Calculates the dot product. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The dot product.. </returns>
        float Dot( const Vector3& vector ) const;

        /// <summary>
        /// Calculates the cross product.
        /// </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns>
        /// A Vector3.
        /// </returns>
        Vector3 Cross( const Vector3& vector ) const;

        /// <summary> Gets the squared length. </summary>
        /// <returns> The squared length. </returns>
        float LengthSquared( ) const;

        /// <summary> Gets the length. </summary>
        /// <returns> The length.. </returns>
        float Length( ) const;

        /// <summary> Gets the normalized vector. </summary>
        /// <returns> A Vector3. </returns>
        Vector3 Normalized( ) const;

        /// <summary> Normalizes the vector. </summary>
        void Normalize( );

        /// <summary> Addition operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector3 operator+( Vector3 vector ) const;

        /// <summary> Addition assignment operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        void operator+=( const Vector3& vector );

        /// <summary> Subtraction operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        Vector3 operator-( const Vector3& vector ) const;

        /// <summary> Subtraction assignment operator. </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns> The result of the operation. </returns>
        void operator-=( const Vector3& vector );

        /// <summary> Division operator. </summary>
        /// <param name="value"> The value. </param>
        /// <returns> The result of the operation. </returns>
        Vector3 operator/( const float value ) const;

        /// <summary>
        /// Division operator.
        /// </summary>
        /// <param name="vector"> The vector. </param>
        /// <returns>
        /// The result of the operation.
        /// </returns>
        Vector3 operator/( const Vector3& vector ) const;

        /// <summary>
        /// Division assignment operator.
        /// </summary>
        /// <param name="value"> The value. </param>
        void Vector3::operator/=( const float value );

        /// <summary>
        /// Multiplication assignment operator.
        /// </summary>
        /// <param name="value"> The value. </param>
        void operator*=( const float value );

        /// <summary> Multiplication operator. </summary>
        /// <param name="value"> The value. </param>
        /// <returns> The result of the operation. </returns>
        Vector3 operator*( Vector3 value ) const;

        /// <summary>
        /// Multiplication operator.
        /// </summary>
        /// <param name="value"> The value. </param>
        /// <returns>
        /// The result of the operation.
        /// </returns>
        Vector3 operator*( const float value ) const;

        /// <summary>
        /// Negate operator
        /// </summary>
        Vector3 operator-( ) const;

        /// <summary> Stream insertion operator. </summary>
        /// <param name="out"> [in,out] The output stream. </param>
        /// <param name="v">   The Vector3 to process. </param>
        /// <returns> The written stream. </returns>
        friend std::ostream& operator<<( std::ostream& out, const Vector3& v );

        /// <summary> The X coordinate. </summary>
        float X;

        /// <summary> The Y coordinate. </summary>
        float Y;

        /// <summary> The Z coordinate. </summary>
        float Z;
    };

}
#endif

