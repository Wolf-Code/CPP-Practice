#pragma once
#include "Engine.h"
#ifndef __PATHTRACERENGINE_H__
#define __PATHTRACERENGINE_H__

/// <summary> The engine implementation for tetris. </summary>
class PathTracerEngine : public Engine
{
public:
    PathTracerEngine( int argc, char** argv );
    ~PathTracerEngine( );

    void OnWindowResize( int width, int height ) override;
    void OnLoad( ) override;
    void OnRender( ) override;
};

#endif