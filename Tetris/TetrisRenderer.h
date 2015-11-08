#pragma once
#ifndef __TETRISRENDERER_H__
#include "Renderer.h"

class TetrisRenderer : public Renderer
{
public:
    TetrisRenderer( int argc, char** argv );
    ~TetrisRenderer( );

    void OnWindowResize( int width, int height ) override;
    void OnLoad( ) override;
    void OnRender( ) override;
};

#endif