#include "Vector2.h"

///-------------------------------------------------------------------------------------------------
/// <summary> Default constructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
///-------------------------------------------------------------------------------------------------
Vector2::Vector2( )
{
    this->X = 0;
    this->Y = 0;
}

///-------------------------------------------------------------------------------------------------
/// <summary> Constructor. </summary>
/// <remarks> Wolf, 08-Nov-15. </remarks>
/// <param name="X"> The X coordinate. </param>
/// <param name="Y"> The Y coordinate. </param>
///-------------------------------------------------------------------------------------------------
Vector2::Vector2(float X, float Y)
{
    this->X = X;
    this->Y = Y;
}
