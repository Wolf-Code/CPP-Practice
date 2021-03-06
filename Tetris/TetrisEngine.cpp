#include "stdafx.h"
#include "TetrisEngine.h"

TetrisEngine::TetrisEngine( int argc, char** argv ) : CPPEngine::Engine( argc, argv )
{

}

void TetrisEngine::OnWindowResize( int width, int height )
{
    CPPEngine::Engine::OnWindowResize( width, height );
}

void TetrisEngine::OnLoad( )
{
    std::cout << "Loaded renderer" << std::endl;
}

void TetrisEngine::OnRender( )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glBegin( GL_TRIANGLES );
    glVertex3f( 0, 0, 0.0 );
    glVertex3f( this->GetWidth( ), 0.0, 0.0 );
    glVertex3f( this->inputHandler.GetMouseX( ), this->inputHandler.GetMouseY( ), 0.0 );
    glEnd( );
}

TetrisEngine::~TetrisEngine( )
{

}