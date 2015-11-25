#include "stdafx.h"
#include "PathTracerEngine.h"
#include "Vector3.h"
#include "SphereObject.h"
#include "Camera.h"

PathTracerEngine::PathTracerEngine( int argc, char** argv ) : Engine( argc, argv ), Pixels( nullptr )
{

}

void PathTracerEngine::OnLoad( )
{
    std::cout << "Loaded renderer" << std::endl;

    this->Pixels = new float[ this->GetWidth( ) * this->GetHeight( ) * 3 ];
}

void PathTracerEngine::OnWindowResize( int width, int height )
{
    Engine::OnWindowResize( width, height );

    delete[ ] this->Pixels;
    this->Pixels = new float[ width * height * 3 ];
}

void PathTracerEngine::OnRender( )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    SphereObject Obj( CPPEngine::Vector3( 0, 0, -100 ), 50 );
    Obj.SurfaceMaterial.Diffuse = CPPEngine::Color( 0.4f, 0.2f, 0.6f );

    CPPEngine::Camera Cam;
    Cam.SetFOV( 90, false );
    Cam.SetResolution( CPPEngine::Vector2( this->GetWidth( ), this->GetHeight( ) ) );

    for ( int x = 0; x < this->GetWidth( ); x++ )
        for ( int y = 0; y < this->GetHeight( ); y++ )
        {
            Ray R = Cam.GetRay( x, y );


            HitResult Res = Obj.GetCollision( R );
            if ( Res.Hit )
            {
                int idx = ( y * this->GetWidth( ) + x ) * 3;
                Pixels[ idx ] = Res.Object->SurfaceMaterial.Diffuse.R;
                Pixels[ idx + 1 ] = Res.Object->SurfaceMaterial.Diffuse.G;
                Pixels[ idx + 2 ] = Res.Object->SurfaceMaterial.Diffuse.B;
            }
        }
    glDrawPixels( this->GetWidth( ), this->GetHeight( ), GL_RGB, GL_FLOAT, Pixels );

    std::cout << "Frame" << std::endl;
}

PathTracerEngine::~PathTracerEngine( )
{
    delete[ ] this->Pixels;
}