#include "stdafx.h"
#include "PathTracerEngine.h"
#include "Vector3.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Ray.h"
#include "PathTracerCalculator.h"
#include "PathTracerSettings.h"

PathTracerEngine::PathTracerEngine( int argc, char** argv ) : Engine( argc, argv ), Pixels( nullptr ), RenderScene( Scene( ) )
{
    const float floorSize = 50;
    SphereObject* floor = new SphereObject( CPPEngine::Vector3( 0, -floorSize, 0 ), floorSize );
    floor->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( 0.2f, 0.2f, 1.0f );
    this->RenderScene.AddObject( floor );

    float sizes[ ] = { 
        2, 
        6,
        1,
    };
    const CPPEngine::Vector3 positions[ ] = { 
        CPPEngine::Vector3( -5, sizes[ 0 ], -8 ),
        CPPEngine::Vector3( 8, sizes[ 1 ], -14 ),
        CPPEngine::Vector3( 0, sizes[ 2 ], -6 ),
    };
    const CPPEngine::Color colors[ ] = { 
        CPPEngine::Color( 1, 0, 0 ), 
        CPPEngine::Color( 0.3f, 0.9f, 0.2f ),
        CPPEngine::Color::White( ),
    };
    const CPPEngine::Color emitColors[ ] = {
        CPPEngine::Color::Black( ),
        CPPEngine::Color::Black( ),
        CPPEngine::Color( 1, 1, 1 ),
    };

    for ( int q = 0; q < sizeof( sizes ) / sizeof( *sizes ); q++)
    {
        SphereObject* s = new SphereObject( positions[ q ], sizes[ q ] );
        s->SurfaceMaterial.ColorDiffuse = colors[ q ];
        s->SurfaceMaterial.ColorEmission = emitColors[ q ];
        this->RenderScene.AddObject( s );
    }
    /*
    const float roomSize = 200;
    const float wallSize = 2000;
    
    SphereObject* ceilingLight = new SphereObject( CPPEngine::Vector3( 0, 0, -75 ), 30 );
    ceilingLight->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( 0, 1, 1 );
    ceilingLight->SurfaceMaterial.ColorEmission = CPPEngine::Color( 10, 10, 10 );
    this->RenderScene.AddObject( ceilingLight );
    
    SphereObject* rearWall = new SphereObject( CPPEngine::Vector3( 0, 0, -1 ) * wallSize - CPPEngine::Vector3( 0, 0, roomSize / 2.0f ), wallSize );
    rearWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color::White( );
    this->RenderScene.AddObject( rearWall );
    
    SphereObject* frontWall = new SphereObject( CPPEngine::Vector3( 0, 0, 1 ) * wallSize + CPPEngine::Vector3( 0, 0, roomSize / 2.0f ), wallSize );
    frontWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color::White( );
    this->RenderScene.AddObject( frontWall );
    
    SphereObject* ceilingWall = new SphereObject( CPPEngine::Vector3( 0, 1, 0 ) * wallSize + CPPEngine::Vector3( 0, roomSize / 2.0f, 0 ), wallSize );
    ceilingWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( 0.2f, 0.6f, 0.5f );
    this->RenderScene.AddObject( ceilingWall );
    
    SphereObject* floorWall = new SphereObject( CPPEngine::Vector3( 0, -1, 0 ) * wallSize - CPPEngine::Vector3( 0, roomSize / 2.0f, 0 ), wallSize );
    floorWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( 1.0f, 0.5f, 0.0f );
    this->RenderScene.AddObject( floorWall );
    
    SphereObject* leftWall = new SphereObject( CPPEngine::Vector3( 1, 0, 0 ) * wallSize + CPPEngine::Vector3( roomSize / 2.0f, 0, 0 ), wallSize );
    leftWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( .75f, .25f, .25f );
    this->RenderScene.AddObject( leftWall );
    
    SphereObject* rightWall = new SphereObject( CPPEngine::Vector3( -1, 0, 0 ) * wallSize - CPPEngine::Vector3( roomSize / 2.0f, 0, 0 ), wallSize );
    rightWall->SurfaceMaterial.ColorDiffuse = CPPEngine::Color( .25f, .25f, .75f );
    this->RenderScene.AddObject( rightWall );*/
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
        Cam.SetFOV( 70, false );
        Cam.SetResolution( this->GetWidth( ), this->GetHeight( ) );
        Cam.SetPosition( CPPEngine::Vector3( 0, 3, 0 ) );
        for ( int y = 0; y < this->GetHeight( ); y++ )
        {
            const Ray R = Cam.GetRay( x, y );
            CPPEngine::Color accumulated = CPPEngine::Color::Black( );

            for ( int q = 0; q < SAMPLES; q++ )
            {
                CPPEngine::Color resultColor = PathTracerCalculator::GetTraceColor( this->RenderScene, R );
                accumulated += resultColor;
            }
            const int idx = ( y * this->GetWidth( ) + x ) * 3;

            accumulated /= float( SAMPLES );
            Pixels[ idx ] = accumulated.R;
            Pixels[ idx + 1 ] = accumulated.G;
            Pixels[ idx + 2 ] = accumulated.B;
        }
    }
    glDrawPixels( this->GetWidth( ), this->GetHeight( ), GL_RGB, GL_FLOAT, Pixels );

    std::cout << "Frame" << std::endl;
}

PathTracerEngine::~PathTracerEngine( )
{
    delete[ ] this->Pixels;
}