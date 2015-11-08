#include "stdafx.h"
#include "TetrisRenderer.h"

TetrisRenderer::TetrisRenderer( int argc, char** argv ) : Renderer( argc, argv )
{

}

void TetrisRenderer::OnWindowResize( int width, int height )
{
    Renderer::OnWindowResize( width, height );
    std::cout << width << '+' << height << std::endl;
}

void TetrisRenderer::OnLoad( )
{
    std::cout << "Loaded renderer" << std::endl;
}

void TetrisRenderer::OnRender( )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glBegin( GL_TRIANGLES );
    glVertex3f( 0, 0, 0.0 );
    glVertex3f( this->GetWidth( ), 0.0, 0.0 );
    glVertex3f( this->GetWidth( ) / 2.0, 200, 0.0 );
    glEnd( );
}

TetrisRenderer::~TetrisRenderer( )
{

}