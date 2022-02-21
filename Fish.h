#pragma once
#include "Animal.h"
class Fish :
    public Animal
{
    DECLARE_SERIAL(Fish)
private:
    int _distanceToTailX[3] = { -10,20,-10 };
    int _distanceToTailY[3] = { 5,15,25 };
public:
    Fish() {};
    Fish(CPoint allowedPosBottomRight, CPoint allowedPosTopLeft);
    int* getDistanceToTailX();
    int* getDistanceToTailY();
};

