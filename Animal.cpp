#include "pch.h"
#include "Animal.h"

IMPLEMENT_SERIAL(Animal, CObject, 1)

Animal::Animal(CPoint allowedPosBottomRight,CPoint allowedPosTopLeft) {
	this->animalPos.x = ((allowedPosBottomRight.x + allowedPosTopLeft.x) / 2) - 70;
	this->animalPos.y = ((allowedPosBottomRight.y + allowedPosTopLeft.y) / 2) - 50;
}

CPoint Animal::getCord() const
{
	return this->animalPos;
}

void Animal::setCord(CPoint cord)
{
	this->animalPos = cord;
}

void Animal::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << animalPos;
	}
	else 
	{
		ar >> animalPos;
	}
}