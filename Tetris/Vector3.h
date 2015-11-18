#pragma once
#ifndef __VECTOR3_H__
#define __VECTOR3_H__
#include "stdafx.h"
#include <math.h>

struct Vector3
{
public:

    /// <summary> Constructor. </summary>
    /// <param name="x"> The x coordinate. </param>
    /// <param name="y"> The y coordinate. </param>
    /// <param name="z"> The z coordinate. </param>
    Vector3( float x = 0, float y = 0, float z = 0 ) : X( x ), Y( y ), Z( z ) {};

    /// <summary> The X coordinate. </summary>
    float X;
    
    /// <summary> The Y coordinate. </summary>
    float Y;

    /// <summary> The Z coordinate. </summary>
    float Z;

    /// <summary> Calculates the dot product. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The dot product.. </returns>
    float Dot( const Vector3& vector ) const { return this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z; }

    /// <summary> Gets the squared length. </summary>
    /// <returns> The squared length. </returns>
    float LengthSquared( ) const { return this->Dot( *this ); };

    /// <summary> Gets the length. </summary>
    /// <returns> The length.. </returns>
    float Length( ) const { return sqrtf( this->LengthSquared( ) ); };

    /// <summary> Gets the normalized vector. </summary>
    /// <returns> A Vector3. </returns>
    Vector3 Normalized( ) const { return *this / this->Length( ); };

    /// <summary> Normalizes the vector. </summary>
    void Normalize( ) { *this /= this->Length( ); };

    /// <summary> Addition operator. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The result of the operation. </returns>
    Vector3 operator+( Vector3 vector ) const
    {
        vector.X += this->X;
        vector.Y += this->Y;
        vector.Z += this->Z;

        return vector;
    }

    /// <summary> Addition assignment operator. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The result of the operation. </returns>
    Vector3& operator+=( const Vector3& vector )
    {
        this->X += vector.X;
        this->Y += vector.Y;
        this->Z += vector.Z;

        return *this;
    }

    /// <summary> Subtraction operator. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The result of the operation. </returns>
    Vector3 operator-( Vector3 vector ) const
    {
        vector.X -= this->X;
        vector.Y -= this->Y;
        vector.Z -= this->Z;

        return vector;
    }

    /// <summary> Subtraction assignment operator. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The result of the operation. </returns>
    Vector3& operator-=( const Vector3& vector )
    {
        this->X -= vector.X;
        this->Y -= vector.Y;
        this->Z -= vector.Z;

        return *this;
    }

    /// <summary> Division operator. </summary>
    /// <param name="value"> The value. </param>
    /// <returns> The result of the operation. </returns>
    Vector3 operator/( const float value ) const
    {
        Vector3 V( this->X, this->Y, this->Z );
        V.X /= value;
        V.Y /= value;
        V.Z /= value;

        return V;
    }

    /// <summary> Addition assignment operator. </summary>
    /// <param name="vector"> The vector. </param>
    /// <returns> The result of the operation. </returns>
    Vector3& operator/=( const float value )
    {
        this->X /= value;
        this->Y /= value;
        this->Z /= value;

        return *this;
    }

    /// <summary> Multiplication operator. </summary>
    /// <param name="V">     The first value to multiply. </param>
    /// <param name="value"> The second value to multiply. </param>
    /// <returns> The result of the operation. </returns>
    friend Vector3 operator*( Vector3 v, const float value )
    {
        v.X *= value;
        v.Y *= value;
        v.Z *= value;

        return v;
    }

    /// <summary> Multiplication operator. </summary>
    /// <param name="value"> The first value to multiply. </param>
    /// <param name="v">     The second value to multiply. </param>
    /// <returns> The result of the operation. </returns>
    friend Vector3 operator*( const float value, Vector3 v )
    {
        v.X *= value;
        v.Y *= value;
        v.Z *= value;

        return v;
    }

    /// <summary> Multiplication assignment operator. </summary>
    /// <param name="value"> The value. </param>
    /// <returns> The result of the operation. </returns>
    Vector3& operator*=( const float value )
    {
        this->X /= value;
        this->Y /= value;
        this->Z /= value;

        return *this;
    }

    /// <summary> Multiplication operator. </summary>
    /// <param name="value"> The value. </param>
    /// <returns> The result of the operation. </returns>
    Vector3 operator*( Vector3 value ) const
    {
        value.X *= this->X;
        value.Y *= this->Y;
        value.Z *= this->Z;

        return value;
    }

    /// <summary> Stream insertion operator. </summary>
    /// <param name="out"> [in,out] The output stream. </param>
    /// <param name="v">   The Vector3 to process. </param>
    /// <returns> The written stream. </returns>
    friend std::ostream& operator<<( std::ostream& out, const Vector3& v )
    {
        return out << 
            "{" << v.X << ", " <<
            v.Y << ", " <<
            v.Z << "}";
    };
};
#endif

