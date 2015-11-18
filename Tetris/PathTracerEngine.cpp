#include "stdafx.h"
#include "PathTracerEngine.h"
#include "Vector3.h"
#include "SphereObject.h"

PathTracerEngine::PathTracerEngine( int argc, char** argv ) : Engine( argc, argv )
{

}

void PathTracerEngine::OnWindowResize( int width, int height )
{
    Engine::OnWindowResize( width, height );
}

void PathTracerEngine::OnLoad( )
{
    std::cout << "Loaded renderer" << std::endl;

    SphereObject Obj( Vector3( 10, 0, 0 ), 5 );
    Ray R( Vector3( 0, 0, 0 ), Vector3( 1, 0, 0 ) );

    HitResult Res = Obj.GetCollision( R );
    std::cout << Res.Hit << std::endl;
    std::cout << Res.Object << std::endl;
}

void PathTracerEngine::OnRender( )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glBegin( GL_TRIANGLES );
    glVertex3f( 0, 0, 0.0 );
    glVertex3f( this->GetWidth( ), 0.0, 0.0 );
    glVertex3f( this->inputHandler.GetMouseX( ), this->inputHandler.GetMouseY( ), 0.0 );
    glEnd( );
}

PathTracerEngine::~PathTracerEngine( )
{

}