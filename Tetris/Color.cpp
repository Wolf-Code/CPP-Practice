#include "Color.h"
#include "stdafx.h"

static CPPEngine::Color black = CPPEngine::Color( );
static CPPEngine::Color white = CPPEngine::Color( 1.0f, 1.0f, 1.0f );

const CPPEngine::Color& CPPEngine::Color::Black( )
{
    return black;
}

const CPPEngine::Color& CPPEngine::Color::White( )
{
    return white;
}

void CPPEngine::Color::operator+=( const CPPEngine::Color& color )
{
    this->R += color.R;
    this->G += color.G;
    this->B += color.B;
}

CPPEngine::Color CPPEngine::Color::operator+( Color& color ) const
{
    color.R += this->R;
    color.G += this->G;
    color.B += this->B;

    return color;
}

CPPEngine::Color CPPEngine::Color::operator*(Color& color) const
{
    color.R *= this->R;
    color.G *= this->G;
    color.B *= this->B;

    return color;
}

CPPEngine::Color CPPEngine::Color::operator*( const Color& color ) const
{
    return Color( color.R * this->R, color.G * this->G, color.B * this->B );
}

void CPPEngine::Color::operator*=( const Color& color )
{
    this->R *= color.R;
    this->G *= color.G;
    this->B *= color.B;
}

void CPPEngine::Color::operator*=(const float mul)
{
    this->R *= mul;
    this->G *= mul;
    this->B *= mul;
}

void CPPEngine::Color::operator/=(const float div)
{
    this->R /= div;
    this->G /= div;
    this->B /= div;
}
