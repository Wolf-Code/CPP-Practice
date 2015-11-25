#include "Vector3.h"

float CPPEngine::Vector3::Dot( const Vector3& vector ) const { return this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z; }

float CPPEngine::Vector3::LengthSquared( ) const { return this->Dot( *this ); };

float CPPEngine::Vector3::Length( ) const
{
    float l = this->LengthSquared( );
    if ( l == 0 )
        throw std::exception( "Attempt to divide by zero. The vector length (squared) is zero." );

    return sqrtf( l );
};

CPPEngine::Vector3 CPPEngine::Vector3::Normalized( ) const
{
    return *this / this->Length( );
};

void CPPEngine::Vector3::Normalize( )
{
    *this /= this->Length( );
};

CPPEngine::Vector3 CPPEngine::Vector3::operator+( Vector3 vector ) const
{
    vector.X += this->X;
    vector.Y += this->Y;
    vector.Z += this->Z;

    return vector;
}

CPPEngine::Vector3& CPPEngine::Vector3::operator+=( const Vector3& vector )
{
    this->X += vector.X;
    this->Y += vector.Y;
    this->Z += vector.Z;

    return *this;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator-( Vector3 vector ) const
{
    vector.X -= this->X;
    vector.Y -= this->Y;
    vector.Z -= this->Z;

    return vector;
}

CPPEngine::Vector3& CPPEngine::Vector3::operator-=( const Vector3& vector )
{
    this->X -= vector.X;
    this->Y -= vector.Y;
    this->Z -= vector.Z;

    return *this;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator/( const float value ) const
{
    Vector3 V( this->X, this->Y, this->Z );
    V.X /= value;
    V.Y /= value;
    V.Z /= value;

    return V;
}

CPPEngine::Vector3& CPPEngine::Vector3::operator/=( const float value )
{
    this->X /= value;
    this->Y /= value;
    this->Z /= value;

    return *this;
}

CPPEngine::Vector3& CPPEngine::Vector3::operator*=( const float value )
{
    this->X /= value;
    this->Y /= value;
    this->Z /= value;

    return *this;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator*( Vector3 value ) const
{
    value.X *= this->X;
    value.Y *= this->Y;
    value.Z *= this->Z;

    return value;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator*( const float value ) const
{
    Vector3 v = *this;
    v.X *= value;
    v.Y *= value;
    v.Z *= value;

    return v;
}

std::ostream& operator<<( std::ostream& out, const CPPEngine::Vector3& v )
{
    return out << "{" << v.X << ", " << v.Y << ", " << v.Z << "}";
};