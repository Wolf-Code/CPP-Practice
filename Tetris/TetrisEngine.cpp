#include "stdafx.h"
#include "TetrisEngine.h"

TetrisEngine::TetrisEngine( int argc, char** argv ) : Engine( argc, argv )
{

}

void TetrisEngine::OnWindowResize( int width, int height )
{
    Engine::OnWindowResize( width, height );
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
    glVertex3f( this->GetWidth( ) / 2.0, 200, 0.0 );
    glEnd( );
}

TetrisEngine::~TetrisEngine( )
{

}