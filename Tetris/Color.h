#pragma once
#ifndef __COLOR_H__
#define __COLOR_H__

namespace CPPEngine
{
    struct Color
    {
        explicit Color( float r, float g, float b ) : R( r ), G( g ), B( b ) {};
        explicit Color( float val = 0 ) :R( val ), G( val ), B( val ) {};

        static const Color& Black( );
        static const Color& White( );

        void operator+=( const Color& color );
        Color operator+( Color& color ) const;
        Color operator*( Color& color ) const;
        Color operator*( const Color& color ) const;
        void operator*=( const Color& color );
        void operator*=( const float mul );
        void operator/=( const float div );

        float R;
        float G;
        float B;
    };
}
#endif