#pragma once
#include "Animal.h"

class Mammal :
    public Animal
{
    DECLARE_SERIAL(Mammal)
private:
    const int _distanceToHeadX = 80;
    const int _distanceToHeadY = 20;
public:
    Mammal() {};
    Mammal(CPoint allowedPosBottomRight,CPoint allowedPosTopLeft);
    int getDistanceToHeadX()const;
    int getDistanceToHeadY()const;
};

