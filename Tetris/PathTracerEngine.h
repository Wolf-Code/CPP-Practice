#pragma once
#ifndef __PATHTRACERENGINE_H__
#define __PATHTRACERENGINE_H__
#include "Engine.h"
#include "Scene.h"

/// <summary> The engine implementation for tetris. </summary>
class PathTracerEngine : public CPPEngine::Engine
{
public:
    PathTracerEngine( int argc, char** argv );
    ~PathTracerEngine( );

    void OnWindowResize( int width, int height ) override;
    void OnLoad( ) override;
    void OnRender( ) override;

private:
    float* Pixels;
    Scene RenderScene;
};

#endif