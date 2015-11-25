#include "stdafx.h"
#include "InputHandler.h"

CPPEngine::InputHandler* m_This;

void MouseFunc( int button, int state, int x, int y )
{
    handler_OnMouseButtonChanged( button, state, x, y, *m_This );
}

void CPPEngine::handler_OnMouseButtonChanged( int button, int state, int x, int y, CPPEngine::InputHandler& inputHandler )
{
    inputHandler.OnMouseButtonChange( button, state, x, y );
}

void MouseMove( int x, int y )
{
    handler_OnMouseMove( x, y, *m_This );
}

void CPPEngine::handler_OnMouseMove( int x, int y, CPPEngine::InputHandler& inputHandler )
{
    inputHandler.OnMouseMove( x, y );
}

CPPEngine::InputHandler::InputHandler( ) : mousePos( )
{
    m_This = this;
}

CPPEngine::InputHandler::~InputHandler( )
{
}

void CPPEngine::InputHandler::Initialize()
{
    glutMouseFunc( MouseFunc );
    glutPassiveMotionFunc( MouseMove );
}

void CPPEngine::InputHandler::OnMouseButtonChange( int button, int state, int x, int y )
{

}

void CPPEngine::InputHandler::OnMouseMove( int x, int y )
{
    this->mousePos.X = x;
    this->mousePos.Y = y;
}

int CPPEngine::InputHandler::GetMouseX( ) const
{
    return this->mousePos.X;
}

int CPPEngine::InputHandler::GetMouseY( ) const
{
    return this->mousePos.Y;
}