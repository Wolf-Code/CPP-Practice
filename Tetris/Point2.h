#pragma once
#ifndef __POINT2_H__

/// <summary> A 2D point. </summary>
struct Point2
{
public:
    Point2( int X = 0, int Y = 0 );

    /// <summary> Addition operator. </summary>
    /// <param name="point"> The point. </param>
    /// <returns> The result of the operation. </returns>
    Point2 operator+( Point2 point ) const
    {
        point.X += this->X;
        point.Y += this->Y;

        return point;
    }

    /// <summary> Subtraction operator. </summary>
    /// <param name="point"> The point. </param>
    /// <returns> The result of the operation. </returns>
    Point2 operator-( Point2 point ) const
    {
        point.X -= this->X;
        point.Y -= this->Y;

        return point;
    }

    /// <summary> Addition assignment operator. </summary>
    /// <param name="point"> The point. </param>
    /// <returns> The result of the operation. </returns>
    Point2& operator+=( const Point2& point )
    {
        this->X += point.X;
        this->Y += point.Y;

        return *this;
    }

    /// <summary> The X coordinate. </summary>
    int X;

    /// <summary> The Y coordinate. </summary>
    int Y;
};

#endif