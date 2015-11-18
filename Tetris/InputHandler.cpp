#include "stdafx.h"
#include "InputHandler.h"

InputHandler* m_This;

void MouseFunc( int button, int state, int x, int y )
{
    handler_OnMouseButtonChanged( button, state, x, y, *m_This );
}

void handler_OnMouseButtonChanged( int button, int state, int x, int y, InputHandler& inputHandler )
{
    inputHandler.OnMouseButtonChange( button, state, x, y );
}

void MouseMove( int x, int y )
{
    handler_OnMouseMove( x, y, *m_This );
}

void handler_OnMouseMove( int x, int y, InputHandler& inputHandler )
{
    inputHandler.OnMouseMove( x, y );
}

InputHandler::InputHandler( ) : mousePos( )
{
    m_This = this;
}

InputHandler::~InputHandler( )
{
}

void InputHandler::Initialize()
{
    glutMouseFunc( MouseFunc );
    glutPassiveMotionFunc( MouseMove );
}

void InputHandler::OnMouseButtonChange( int button, int state, int x, int y )
{

}

void InputHandler::OnMouseMove( int x, int y )
{
    this->mousePos.X = x;
    this->mousePos.Y = y;
}

int InputHandler::GetMouseX( ) const
{
    return this->mousePos.X;
}

int InputHandler::GetMouseY( ) const
{
    return this->mousePos.Y;
}
