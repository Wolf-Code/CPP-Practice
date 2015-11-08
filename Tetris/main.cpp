#include "stdafx.h"
#include "TetrisRenderer.h"

///-------------------------------------------------------------------------------------------------
/// <summary> The program's entry point. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="argc"> The amount of arguments. </param>
/// <param name="argv"> The arguments. </param>
/// <returns> A code indicating the succes or error whilst running. </returns>
///-------------------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
    TetrisRenderer R( argc, argv );
    // init GLUT and create Window. 
    R.Initialize( "OpenGL!", GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA, Point2( 100, 100 ), Point2( 320, 320 ) );

    return 1;

}