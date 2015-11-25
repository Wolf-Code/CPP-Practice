#include "Matrix4x4.h"
#include "Vector3.h"
#include <exception>
#include "MathHelper.h"

static const Matrix4x4& identity = Matrix4x4( 1, 1, 1, 1,
                                             1, 1, 1, 1,
                                             1, 1, 1, 1,
                                             1, 1, 1, 1 );

static const Matrix4x4& zero = Matrix4x4( 0, 0, 0, 0,
                                         0, 0, 0, 0,
                                         0, 0, 0, 0,
                                         0, 0, 0, 0 );

Matrix4x4::Matrix4x4( float m00, float m10, float m20, float m30, float m01, float m11, float m21, float m31, float m02, float m12, float m22, float m32, float m03, float m13, float m23, float m33 )
    : Data( new float[ 16 ]{ m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33 } )
{

}

Matrix4x4::Matrix4x4( const Matrix4x4& m )
{
    this->Data = new float[ m.Dimensions * m.Dimensions ];
    for ( int x = 0; x < this->Dimensions; x++ )
        for ( int y = 0; y < this->Dimensions; y++ )
            this->SetValue( x, y, m.GetValue( x, y ) );
}

Matrix4x4::~Matrix4x4( )
{
    /*
    for ( int y = 0; y < this->Dimensions; y++ )
    {
        for ( int x = 0; x < this->Dimensions; x++ )
            std::cout << this->GetValue( x, y ) << " ";

        std::cout << std::endl;
    }*/

    delete[ ] this->Data;
}

float Matrix4x4::GetValue( const int x, const int y ) const
{
    if ( x >= Dimensions || y >= Dimensions || x < 0 || y < 0 )
        throw std::exception( "Position outside matrix bounds." );

    return this->Data[ y * this->Dimensions + x ];
}

void Matrix4x4::SetValue( const int x, const int y, float value ) const
{
    if ( x >= Dimensions || y >= Dimensions || x < 0 || y < 0 )
        throw std::exception( "Position outside matrix bounds." );

    this->Data[ y * this->Dimensions + x ] = value;
}

void Matrix4x4::AddValue( const int x, const int y, float value ) const
{
    if ( x >= Dimensions || y >= Dimensions || x < 0 || y < 0 )
        throw std::exception( "Position outside matrix bounds." );

    float& val = this->Data[ y * this->Dimensions + x ];
    val += value;
}

CPPEngine::Vector3 Matrix4x4::Forward( ) const
{
    return CPPEngine::Vector3( this->GetValue( 2, 0 ), this->GetValue( 2, 1 ), this->GetValue( 2, 2 ) );
}

CPPEngine::Vector3 Matrix4x4::Right( ) const
{
    return CPPEngine::Vector3( this->GetValue( 0, 0 ), this->GetValue( 0, 1 ), this->GetValue( 0, 2 ) );
}

CPPEngine::Vector3 Matrix4x4::Up( ) const
{
    return CPPEngine::Vector3( this->GetValue( 1, 0 ), this->GetValue( 1, 1 ), this->GetValue( 1, 2 ) );
}

Matrix4x4 Matrix4x4::Identity( )
{
    return Matrix4x4( identity );
}

Matrix4x4 Matrix4x4::Zero( )
{
    return Matrix4x4( zero );
}

Matrix4x4 Matrix4x4::CreateTranslation( const CPPEngine::Vector3& translation )
{
    return Matrix4x4( 1, 0, 0, translation.X,
                      0, 1, 0, translation.Y,
                      0, 0, 1, translation.Z,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::CreateScale( const CPPEngine::Vector3& scale )
{
    return Matrix4x4( scale.X, 0, 0, 0,
                      0, scale.Y, 0, 0,
                      0, 0, scale.Z, 0,
                      0, 0, 0, 0 );
}

Matrix4x4 Matrix4x4::CreateRotationX( const float rotation, bool radians )
{
    float sin = MathHelper::Sin( rotation, radians );
    float cos = MathHelper::Cos( rotation, radians );
    return Matrix4x4( 1, 0, 0, 0,
                      0, cos, -sin, 0,
                      0, sin, cos, 0,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::CreateRotationY( const float rotation, bool radians )
{
    float sin = MathHelper::Sin( rotation, radians );
    float cos = MathHelper::Cos( rotation, radians );
    return Matrix4x4( cos, 0, sin, 0,
                      0, 1, 0, 0,
                      -sin, 0, cos, 0,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::CreateRotationZ( const float rotation, bool radians )
{
    float sin = MathHelper::Sin( rotation, radians );
    float cos = MathHelper::Cos( rotation, radians );
    return Matrix4x4( cos, -sin, 0, 0,
                      sin, cos, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::CreateRotation( const CPPEngine::Vector3& rotation, bool radians )
{
    return CreateRotation( rotation.X, rotation.Y, rotation.Z, radians );
}

Matrix4x4 Matrix4x4::CreateRotation( const float pitch, const float yaw, const float roll, bool radians )
{
    return CreateRotationX( pitch, radians ) *
           CreateRotationY( yaw, radians ) *
           CreateRotationZ( roll, radians );
}

Matrix4x4 Matrix4x4::CreateOrtho( float width, float height, float znear, float zfar )
{
    float farminusnear = zfar - znear;
    return Matrix4x4( 1.0f / width, 0, 0, 0,
                      0, 1.0f / height, 0, 0,
                      0, 0, -( 2.0f / farminusnear ), ( zfar + znear ) / farminusnear,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::CreateProjection( float fovx, float fovy, float znear, float zfar )
{
    float farminusnear = zfar - znear;
    return Matrix4x4( atan( fovx / 2.0f ), 0, 0, 0,
                      0, atan( fovy / 2.0f ), 0, 0,
                      0, 0, -( 2.0f / farminusnear ), ( zfar + znear ) / farminusnear,
                      0, 0, 0, 1 );
}

Matrix4x4 Matrix4x4::operator*( const Matrix4x4& m ) const
{
    Matrix4x4 temp = Matrix4x4( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );

    for ( int i = 0; i < Dimensions; i++ )
        for ( int j = 0; j < Dimensions; j++ )
            for ( int k = 0; k < Dimensions; k++ )
                temp.AddValue( i, j, this->GetValue( i, k ) * m.GetValue( k, j ) );

    return temp;
}

CPPEngine::Vector3 Matrix4x4::operator*( const CPPEngine::Vector3& v ) const
{
    float vmatrix[ 4 ] = { v.X, v.Y, v.Z, 1 };

    float Temp[ 4 ] = { 0, 0, 0, 0 };
    for ( int i = 0; i < Dimensions; i++ )
        for ( int j = 0; j < Dimensions; j++ )
            Temp[ i ] += vmatrix[ j ] * this->GetValue( j, i );

    return CPPEngine::Vector3( Temp[ 0 ], Temp[ 1 ], Temp[ 2 ] );
}

Matrix4x4& Matrix4x4::operator=( const Matrix4x4& m )
{
    if ( this != &m )
    {
        // Remove existing data.
        delete[ ] this->Data;

        // Allocate new data
        this->Data = new float[ m.Dimensions * m.Dimensions ];
        for ( int x = 0; x < this->Dimensions; x++ )
            for ( int y = 0; y < this->Dimensions; y++ )
                this->SetValue( x, y, m.GetValue( x, y ) );
    }

    return *this;
}
