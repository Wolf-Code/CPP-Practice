#pragma once
#ifndef __RAY_H__
#define __RAY_H__
#include "Vector3.h"

struct Ray
{
    Ray( CPPEngine::Vector3 start, CPPEngine::Vector3 direction, unsigned int bounces ) : Start( start ), Direction( direction ), Bounces( bounces ) {};

    CPPEngine::Vector3 Start;
    CPPEngine::Vector3 Direction;
    unsigned int Bounces;
};
#endif

