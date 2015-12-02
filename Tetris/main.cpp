#include "stdafx.h"
#include "Point2.h"
#include "PathTracerEngine.h"

///-------------------------------------------------------------------------------------------------
/// <summary> The program's entry point. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="argc"> The amount of arguments. </param>
/// <param name="argv"> The arguments. </param>
/// <returns> A code indicating the succes or error whilst running. </returns>
///-------------------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
    PathTracerEngine R( argc, argv );
    // init GLUT and create Window. 
    try
    {
        R.Initialize( "OpenGL!", GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA, CPPEngine::Point2( 100, 100 ), CPPEngine::Point2( 100, 100 ) );
    }
    catch( std::exception e )
    {
        std::cout << "Failed to initialize engine: " << std::endl;
    }
    std::cin.clear( );
    std::cin.get( );

    return 0;
}