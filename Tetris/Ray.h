#pragma once
#ifndef __RAY_H__
#define __RAY_H__
#include "Vector3.h"

struct Ray
{
public:
    Ray( Vector3 start, Vector3 direction ) : Start( start ), Direction( direction ) {};

    Vector3 Start;
    Vector3 Direction;
};
#endif

