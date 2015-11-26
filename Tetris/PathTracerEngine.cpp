#include "stdafx.h"
#include "PathTracerEngine.h"
#include "Vector3.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Ray.h"

PathTracerEngine::PathTracerEngine( int argc, char** argv ) : Engine( argc, argv ), Pixels( nullptr ), RenderScene( Scene( ) )
{
    SphereObject* Obj = new SphereObject( CPPEngine::Vector3( 0, 0, -100 ), 50 );
    Obj->SurfaceMaterial.Diffuse = CPPEngine::Color( 0.4f, 0.2f, 0.6f );

    SphereObject* Sun = new SphereObject( CPPEngine::Vector3( 0, 1070, 0 ), 1000 );
    Sun->SurfaceMaterial.Diffuse = CPPEngine::Color::White( );

    this->RenderScene.AddObject( Obj );
    this->RenderScene.AddObject( Sun );
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

    CPPEngine::Camera Cam;
    

#pragma omp parallel for private( Cam )
    for ( int x = 0; x < this->GetWidth( ); x++ )
    {
        Cam.SetFOV( 90, false );
        Cam.SetResolution( this->GetWidth( ), this->GetHeight( ) );

        for ( int y = 0; y < this->GetHeight( ); y++ )
        {
            Ray R = Cam.GetRay( x, y );

            const std::vector<ObjectBase*> objects = this->RenderScene.GetObjects( );
            for ( std::vector<ObjectBase*>::size_type i = 0; i != objects.size( ); i++ )
            {
                const ObjectBase* Obj = objects[ i ];
                const HitResult Res = Obj->GetCollision( R );
                if ( Res.Hit )
                {
                    const int idx = ( y * this->GetWidth( ) + x ) * 3;
                    Pixels[ idx ] = Res.Object->SurfaceMaterial.Diffuse.R;
                    Pixels[ idx + 1 ] = Res.Object->SurfaceMaterial.Diffuse.G;
                    Pixels[ idx + 2 ] = Res.Object->SurfaceMaterial.Diffuse.B;
                }
            }
        }
    }
    glDrawPixels( this->GetWidth( ), this->GetHeight( ), GL_RGB, GL_FLOAT, Pixels );

    std::cout << "Frame" << std::endl;
}

PathTracerEngine::~PathTracerEngine( )
{
    delete[ ] this->Pixels;
}