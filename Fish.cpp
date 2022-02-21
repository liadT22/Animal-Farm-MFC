#include "pch.h"
#include "Fish.h"

IMPLEMENT_SERIAL(Fish, CObject, 1)

Fish::Fish(CPoint allowedPosBottomRight, CPoint allowedPosTopLeft) : Animal(allowedPosBottomRight, allowedPosTopLeft)
{
}

int* Fish::getDistanceToTailX()
{
    return _distanceToTailX;
}

int* Fish::getDistanceToTailY()
{
    return _distanceToTailY;
}
