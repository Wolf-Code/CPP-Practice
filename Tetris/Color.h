#pragma once
#ifndef __COLOR_H__
#define __COLOR_H__

namespace CPPEngine
{
    struct Color
    {
        explicit Color( float r = 0, float g = 0, float b = 0 ) : R( r ), G( g ), B( b ) {};

        static const Color& Black( );
        static const Color& White( );

        float R;
        float G;
        float B;
    };
}
#endif