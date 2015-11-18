#pragma once
#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include "Point2.h"

/// <summary> An input handler. </summary>
class InputHandler
{
public:
    InputHandler( );
    virtual ~InputHandler( );
    friend void handler_OnMouseButtonChanged( int button, int state, int x, int y, InputHandler& inputHandler );
    friend void handler_OnMouseMove( int x, int y, InputHandler& inputHandler );

    void Initialize( );

    int GetMouseX( ) const;
    int GetMouseY( ) const;

protected:
    virtual void OnMouseButtonChange( int button, int state, int x, int y );
    virtual void OnMouseMove( int x, int y );
    
    Point2 mousePos;
};

#endif