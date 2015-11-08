#pragma once
#ifndef __RENDERER_H__
#include "Point2.h"
#include "typedefs.h"

class Renderer
{
public:
    Renderer( int argc, char** argv );
    void Initialize( const unsigned int displayMode, const Point2& position, const Point2& size );
    void SetWindowPosition( const Point2& position );
    void SetWindowSize( const Point2& size );
    void MakeWindow( const char* title );
    void SetDisplayFunc( FUNC_VOID method );
    void MainLoop( void );
    ~Renderer( );

private:
};

#endif