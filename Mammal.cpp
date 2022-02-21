#include "pch.h"
#include "Mammal.h"

IMPLEMENT_SERIAL(Mammal, CObject, 1)

Mammal::Mammal(CPoint allowedPosBottomRight,CPoint allowedPosTopLeft) :Animal(allowedPosBottomRight, allowedPosTopLeft) {
}

int Mammal::getDistanceToHeadY() const
{
	return this->_distanceToHeadY;
}

int Mammal::getDistanceToHeadX() const
{
	return this->_distanceToHeadX;
}
