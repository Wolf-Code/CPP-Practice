#include "HitResult.h"

float HitResult::Distance( ) const
{
    return sqrt( this->DistanceSquared );
};