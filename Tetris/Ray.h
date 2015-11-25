#pragma once
#ifndef __RAY_H__
#define __RAY_H__
#include "Vector3.h"

struct Ray
{
    Ray( CPPEngine::Vector3 start, CPPEngine::Vector3 direction ) : Start( start ), Direction( direction ) {};

    CPPEngine::Vector3 Start;
    CPPEngine::Vector3 Direction;
};
#endif

