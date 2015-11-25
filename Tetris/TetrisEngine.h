#pragma once
#ifndef __TETRISENGINE_H__
#define __TETRISENGINE_H__

#include "Engine.h"

/// <summary> The engine implementation for tetris. </summary>
class TetrisEngine : public CPPEngine::Engine
{
public:
    TetrisEngine( int argc, char** argv );
    ~TetrisEngine( );

    void OnWindowResize( int width, int height ) override;
    void OnLoad( ) override;
    void OnRender( ) override;
};

#endif