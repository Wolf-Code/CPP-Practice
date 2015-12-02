#include "Vector3.h"

float CPPEngine::Vector3::Dot( const Vector3& vector ) const { return this->X * vector.X + this->Y * vector.Y + this->Z * vector.Z; }

CPPEngine::Vector3 CPPEngine::Vector3::Cross( const Vector3& vector ) const
{
    return Vector3(
        this->Y * vector.Z - this->Z * vector.Y,
        this->Z * vector.X - this->X * vector.Z,
        this->X * vector.Y - this->Y * vector.X
        );
}

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

void CPPEngine::Vector3::operator+=( const Vector3& vector )
{
    this->X += vector.X;
    this->Y += vector.Y;
    this->Z += vector.Z;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator-( const Vector3& vector ) const
{
    return Vector3( this->X - vector.X, this->Y - vector.Y, this->Z - vector.Z );
}

void CPPEngine::Vector3::operator-=( const Vector3& vector )
{
    this->X -= vector.X;
    this->Y -= vector.Y;
    this->Z -= vector.Z;
}

CPPEngine::Vector3 CPPEngine::Vector3::operator/( const float value ) const
{
    return Vector3( this->X / value, this->Y / value, this->Z / value );
}

CPPEngine::Vector3 CPPEngine::Vector3::operator/( const Vector3& vector ) const
{
    return Vector3( this->X / vector.X, this->Y / vector.Y, this->Z / vector.Z );
}

void CPPEngine::Vector3::operator/=( const float value )
{
    this->X /= value;
    this->Y /= value;
    this->Z /= value;
}

void CPPEngine::Vector3::operator*=( const float value )
{
    this->X *= value;
    this->Y *= value;
    this->Z *= value;
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
    return Vector3( this->X * value, this->Y * value, this->Z * value );
}

CPPEngine::Vector3 CPPEngine::Vector3::operator-( ) const
{
    return Vector3( -this->X, -this->Y, -this->Z );
}

std::ostream& CPPEngine::operator<<( std::ostream& out, const Vector3& v )
{
    return out << "{" << v.X << ", " << v.Y << ", " << v.Z << "}";
};