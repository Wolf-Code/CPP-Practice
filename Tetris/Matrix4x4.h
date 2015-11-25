#pragma once
#ifndef __MATRIX4x4_H__
#define __MATRIX4x4_H__
#include <string>

namespace CPPEngine
{
    struct Vector3;
}

struct Vector3;

class Matrix4x4
{
public:
    explicit Matrix4x4( float data[ 16 ] ) : Data( data ) {};
    Matrix4x4( float m00, float m10, float m20, float m30,
               float m01, float m11, float m21, float m31,
               float m02, float m12, float m22, float m32,
               float m03, float m13, float m23, float m33 );
    Matrix4x4( const Matrix4x4& m );
    ~Matrix4x4( );

    float GetValue( const int x, const int y ) const;
    void SetValue( const int x, const int y, float value ) const;
    void AddValue( const int x, const int y, float value ) const;

    CPPEngine::Vector3 Forward( ) const;
    CPPEngine::Vector3 Right( ) const;
    CPPEngine::Vector3 Up( ) const;

    static Matrix4x4 Identity( );
    static Matrix4x4 Zero( );

    static Matrix4x4 CreateTranslation( const CPPEngine::Vector3& translation );
    static Matrix4x4 CreateScale( const CPPEngine::Vector3& scale );
    static Matrix4x4 CreateRotationX( const float rotation, bool radians = true );
    static Matrix4x4 CreateRotationY( const float rotation, bool radians = true );
    static Matrix4x4 CreateRotationZ( const float rotation, bool radians = true );
    static Matrix4x4 CreateRotation( const CPPEngine::Vector3& rotation, bool radians = true );
    static Matrix4x4 CreateRotation( const float pitch, const float yaw, const float roll, bool radians = true );

    static Matrix4x4 CreateOrtho( float width, float height, float znear, float zfar );
    static Matrix4x4 CreateProjection( float fovx, float fovy, float znear, float zfar );

    Matrix4x4 operator*( const Matrix4x4& m ) const;
    CPPEngine::Vector3 operator*( const CPPEngine::Vector3& v ) const;
    Matrix4x4& operator=( const Matrix4x4& m );

    const int Dimensions = 4;
private:
    float* Data;
};

#endif


