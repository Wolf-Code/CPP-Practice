#include "stdafx.h"
#include <stdexcept>
#include "Engine.h"

// A way to keep the active Engine accessable for the Glut hooks.
static CPPEngine::Engine* m_This;

// Makes sure the OnWindowResize event is called.
void renderer_OnResize( int width, int height )
{
    handler_OnResize( width, height, *m_This );
}

// Calls the actual events on the instance of Engine.
void CPPEngine::handler_OnResize( int width, int height, CPPEngine::Engine& engine )
{
    engine.OnWindowResize( width, height );
}

// Makes sure the OnRender event is called.
void renderer_OnRender( void )
{
    handler_OnRender( *m_This );
}

// Calls the actual events on the instance of Engine.
void CPPEngine::handler_OnRender( CPPEngine::Engine& engine )
{
    engine.OnUpdate( );
    engine.OnRender( );
    glutSwapBuffers( );
    glutPostRedisplay( );
}


///-------------------------------------------------------------------------------------------------
/// <summary> Default constructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
CPPEngine::Engine::Engine( int argc, char** argv ) : windowIdentifier( 0 ), width( 0 ), height( 0 )
{
    glutInit( &argc, argv );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Initializes the engine. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="displayMode"> The display mode. </param>
/// <param name="position">    The position. </param>
/// <param name="size">        The size. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::Initialize( const char* title, const unsigned int displayMode, const CPPEngine::Point2& position, const CPPEngine::Point2& size )
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
    this->inputHandler.Initialize( );

    this->OnLoad( );

    glutMainLoop( );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's position. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Position"> The position of the window. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::SetWindowPosition( const CPPEngine::Point2& position ) const
{
    glutPositionWindow( position.X, position.Y );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's size. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="Size"> The size of the window. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::SetWindowSize( const CPPEngine::Point2& size ) const
{
    glutReshapeWindow( size.X, size.Y );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's width. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="width"> The width. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::SetWidth( const int width ) const
{
    glutReshapeWindow( width <= 0 ? 1 : width, this->height );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Sets the window's height. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="height"> The height. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::SetHeight( const int height ) const
{
    glutReshapeWindow( this->width, height <= 0 ? 1 : height );
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets called when the window size changes. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="width">  The width. </param>
/// <param name="height"> The height. </param>
///-------------------------------------------------------------------------------------------------
void CPPEngine::Engine::OnWindowResize( const int width, const int height )
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
/// <summary> Gets the width of the display. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <returns> The width. </returns>
///-------------------------------------------------------------------------------------------------
int CPPEngine::Engine::GetWidth( ) const
{
    return this->width;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Gets the height of the display. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <returns> The height. </returns>
///-------------------------------------------------------------------------------------------------
int CPPEngine::Engine::GetHeight( ) const
{
    return this->height;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Destructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
CPPEngine::Engine::~Engine( )
{
    glutDestroyWindow( this->windowIdentifier );
}