#pragma once
#ifndef __POINT2_H__
#define __POINT2_H__


namespace CPPEngine
{
    /// <summary> A 2D point. </summary>
    struct Point2
    {
    public:
        Point2( const int x = 0, const int y = 0 ) : X( x ), Y( y ) {};

        /// <summary> Addition operator. </summary>
        /// <param name="point"> The point. </param>
        /// <returns> The result of the operation. </returns>
        Point2 operator+( Point2 point ) const;

        /// <summary> Subtraction operator. </summary>
        /// <param name="point"> The point. </param>
        /// <returns> The result of the operation. </returns>
        Point2 operator-( Point2 point ) const;

        /// <summary> Addition assignment operator. </summary>
        /// <param name="point"> The point. </param>
        /// <returns> The result of the operation. </returns>
        Point2& operator+=( const Point2& point );

        /// <summary> The X coordinate. </summary>
        int X;

        /// <summary> The Y coordinate. </summary>
        int Y;
    };
}
#endif