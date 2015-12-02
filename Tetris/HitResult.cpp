#include "HitResult.h"

void HitResult::SetDistance( const float distance )
{
    this->RealDistance = distance;
    this->DistanceSquared = distance * distance;
    this->IsDistanceSet = true;
}

float HitResult::Distance( ) const
{
    if ( IsDistanceSet )
        return this->RealDistance;

    return sqrt( this->DistanceSquared );
}
