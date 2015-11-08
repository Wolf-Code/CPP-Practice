#include "stdafx.h"
#include "Renderer.h"

void renderScene( void );

///-------------------------------------------------------------------------------------------------
/// <summary> The program's entry point. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="argc"> The amount of arguments. </param>
/// <param name="argv"> The arguments. </param>
/// <returns> A code indicating the succes or error whilst running. </returns>
///-------------------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
    Renderer R( argc, argv );
    // init GLUT and create Window. 
    R.Initialize( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA, Point2( 100, 100 ), Point2( 320, 320 ) );
    R.MakeWindow( "OpenGL!" );


    R.SetDisplayFunc( renderScene );
    R.MainLoop( );

    return 1;

}

///-------------------------------------------------------------------------------------------------
/// <summary> Renders the scene. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
void renderScene( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glBegin( GL_TRIANGLES );
    glVertex3f( -0.5, -0.5, 0.0 );
    glVertex3f( 0.5, 0.0, 0.0 );
    glVertex3f( 0.0, 0.5, 0.0 );
    glEnd( );

    glutSwapBuffers( );
}