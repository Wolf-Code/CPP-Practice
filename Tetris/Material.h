#pragma once
#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "Color.h"


struct Material
{
    Material( ) : ColorEmission( CPPEngine::Color::Black( ) ), ColorDiffuse( CPPEngine::Color::Black( ) )
    {

    };

    enum Type
    {
        Diffuse,
        Reflective,
        Refractive
    };

    CPPEngine::Color ColorEmission;
    CPPEngine::Color ColorDiffuse;
};
#endif
