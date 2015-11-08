#pragma once
#ifndef __RENDERER_H__
#include "Point2.h"

class Renderer
{
public:
    Renderer( int argc, char** argv );

    void Initialize( const char* Title ,const unsigned int displayMode, const Point2& position, const Point2& size );
    void SetWindowPosition( const Point2& position ) const;
    void SetWindowSize( const Point2& size ) const;
    void SetWidth( const int width ) const;
    void SetHeight( const int height ) const;
    virtual ~Renderer( );

    int GetWidth( void ) const;
    int GetHeight( void ) const;

    virtual void OnWindowResize( int width, int height );
    virtual void OnLoad( void );
    virtual void OnRender( void );
    virtual void OnUpdate( void );

protected:
    int windowIdentifier;

private:
    int width;
    int height;
};

#endif