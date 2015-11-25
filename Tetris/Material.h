#pragma once
#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "Color.h"


struct Material
{
public:
    Material( ) : Diffuse(CPPEngine::Color( ) )
    {

    };

    CPPEngine::Color Diffuse;
};
#endif
