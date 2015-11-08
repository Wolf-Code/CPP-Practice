#include "stdafx.h"
#include "Renderer.h"

///-------------------------------------------------------------------------------------------------
/// <summary> Default constructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
Renderer::Renderer( int argc, char** argv )
{
    glutInit( &argc, argv );
}
///-------------------------------------------------------------------------------------------------
/// <summary> Initializes the renderer. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="displayMode"> The display mode. </param>
/// <param name="position">    The position. </param>
/// <param name="size">        The size. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::Initialize( const unsigned int displayMode, const Point2 & position, const Point2 & size )
{
    glutInitDisplayMode( displayMode );
    glutInitWindowPosition( position.X, position.Y );
    glutInitWindowSize( size.X, size.Y );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's position. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Position"> The position of the window. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetWindowPosition( const Point2& position )
{

}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's size. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Size"> The size of the window. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetWindowSize( const Point2& size )
{
    const int width = size.X;
    const int height = size.Y != 0 ? size.Y : 1;

    // Use the Projection Matrix
    glMatrixMode( GL_PROJECTION );

    // Reset Matrix
    glLoadIdentity( );

    // Set the viewport to be the entire window
    glViewport( 0, 0, width, height );

    // Set the correct perspective.
    gluOrtho2D( 0, width, height, 0 );

    // Get Back to the Modelview
    glMatrixMode( GL_MODELVIEW );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Makes a window with a given title. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="title"> The title. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::MakeWindow( const char* title )
{
    glutCreateWindow( title );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the render method. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="method"> The method. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetDisplayFunc( FUNC_VOID method )
{
    glutDisplayFunc( method );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Starts the main loop. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
void Renderer::MainLoop()
{
    glutMainLoop( );
}

Renderer::~Renderer( )
{
}
