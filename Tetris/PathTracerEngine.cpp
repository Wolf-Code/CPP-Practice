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

    SphereObject Obj( Vector3( this->GetWidth( ) / 2.0F, this->GetHeight( ) / 2.0F, -100 ), 50 );
    Obj.SurfaceMaterial.Diffuse = Color( 1, 0.5f, 0 );
    
    glBegin( GL_POINTS );
    for ( int x = 0; x < this->GetWidth( ); x++ )
        for ( int y = 0; y < this->GetHeight( ); y++ )
        {
            Ray R( Vector3( x, y, 0 ), Vector3( 0, 0, -1 ) );

            HitResult Res = Obj.GetCollision( R );
            if ( Res.Hit )
            {
                glColor3f( Res.Object->SurfaceMaterial.Diffuse.R, Res.Object->SurfaceMaterial.Diffuse.G, Res.Object->SurfaceMaterial.Diffuse.B );
                glVertex3f( x, y, 0 );
            }
        }
    glEnd( );
}

PathTracerEngine::~PathTracerEngine( )
{

}