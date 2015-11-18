#pragma once
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Point2.h"
#include "InputHandler.h"

/// <summary> The base class engine. </summary>
class Engine
{
public:
    Engine( int argc, char** argv );
    virtual ~Engine( );

    friend void handler_OnRender( Engine& engine );
    friend void handler_OnResize( int width, int height, Engine& engine );

    void Initialize( const char* Title ,const unsigned int displayMode, const Point2& position, const Point2& size );
    void SetWindowPosition( const Point2& position ) const;
    void SetWindowSize( const Point2& size ) const;
    void SetWidth( const int width ) const;
    void SetHeight( const int height ) const;

    int GetWidth( ) const;
    int GetHeight( ) const;

protected:
    virtual void OnWindowResize( int width, int height );

    /// <summary> Gets called after the window and hooks have been set up and loaded. </summary>
    virtual void OnLoad( ) {};

    /// <summary> Performs the rendering of a frame. </summary>
    virtual void OnRender( ) {};

    /// <summary> Gets called every frame before OnRender. Use this to update the game world before rendering. </summary>
    virtual void OnUpdate( ) {};

    /// <summary> Identifier for the window. </summary>
    int windowIdentifier;

    /// <summary> The input handler. </summary>
    InputHandler inputHandler;

private:
    int width;
    int height;
};

#endif