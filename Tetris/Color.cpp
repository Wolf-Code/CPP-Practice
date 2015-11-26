#include "Color.h"

static CPPEngine::Color black = CPPEngine::Color( );
static CPPEngine::Color white = CPPEngine::Color( 1.0f, 1.0f, 1.0f );

const CPPEngine::Color& CPPEngine::Color::Black( )
{
    return black;
}

const CPPEngine::Color& CPPEngine::Color::White( )
{
    return white;
}
