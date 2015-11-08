#include "stdafx.h"
#include "Renderer.h"
#include <stdexcept>
#include <iostream>

static Renderer* m_This;

// Makes sure the OnWindowResize event is called.
void renderer_OnResize( int width, int height )
{
    m_This->OnWindowResize( width, height );
}

// Makes sure the OnRender event is called.
void renderer_OnRender( void )
{
    m_This->OnUpdate( );
    m_This->OnRender( );
    glutSwapBuffers( );
    glutPostRedisplay( );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Default constructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
Renderer::Renderer( int argc, char** argv ) : windowIdentifier( 0 )
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
void Renderer::Initialize( const char* title, const unsigned int displayMode, const Point2& position, const Point2& size )
{
    if ( m_This )
        throw std::exception( "Only one instance of the Renderer may be active at any one time." );

    m_This = this;
    glutInitDisplayMode( displayMode );
    glutInitWindowPosition( position.X, position.Y );
    glutInitWindowSize( size.X, size.Y );

    this->windowIdentifier = glutCreateWindow( title );

    glutDisplayFunc( renderer_OnRender );
    glutReshapeFunc( renderer_OnResize );

    glutMainLoop( );

    this->OnLoad( );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's position. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Position"> The position of the window. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetWindowPosition( const Point2& position ) const
{
    glutPositionWindow( position.X, position.Y );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's size. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Size"> The size of the window. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetWindowSize( const Point2& size ) const
{
    glutReshapeWindow( size.X, size.Y );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's width. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="width"> The width. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetWidth( const int width ) const
{
    glutReshapeWindow( width <= 0 ? 1 : width, this->height );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's height. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="height"> The height. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::SetHeight( const int height ) const
{
    glutReshapeWindow( this->width, height <= 0 ? 1 : height );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets called when the window size changes. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="width">  The width. </param>
/// <param name="height"> The height. </param>
///-------------------------------------------------------------------------------------------------
void Renderer::OnWindowResize( const int width, const int height )
{
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

    this->width = width;
    this->height = height;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets called when the renderer has finished loading. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
void Renderer::OnLoad( )
{
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets called whenever a frame needs to be rendered. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
void Renderer::OnRender( )
{
    
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets called every frame, before the actual rendering of the frame. Update the objects in this method. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
void Renderer::OnUpdate()
{

}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets the width of the display. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <returns> The width. </returns>
///-------------------------------------------------------------------------------------------------
int Renderer::GetWidth( ) const
{
    return this->width;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets the height of the display. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <returns> The height. </returns>
///-------------------------------------------------------------------------------------------------
int Renderer::GetHeight( ) const
{
    return this->height;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Destructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
Renderer::~Renderer( )
{
    glutDestroyWindow( this->windowIdentifier );
}
