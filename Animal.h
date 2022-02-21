#pragma once
#include <iostream>
#include <string>
using namespace std;
class Animal : public CObject
{
	DECLARE_SERIAL(Animal)
private:
	CPoint animalPos;
public:
	Animal() { };
	Animal(CPoint allowedPosBottomRight, CPoint allowedPosTopLeft);
	virtual void makeNoise() {}
	CPoint getCord() const;
	void setCord(CPoint cord);
	void Serialize(CArchive& ar);
	virtual int GetId()const { return -1; }
	virtual void play() {}
	virtual void draw(CDC* dc) {}
	virtual int getPlay()const { return NULL; }
	virtual int getDistanceToHeadX()const { return NULL; }
	virtual int getDistanceToHeadY()const { return NULL; }
	virtual int* getDistanceToTailX() { return NULL; }
	virtual int* getDistanceToTailY() { return NULL; }
	virtual CPoint getAllowedPosTopLeft()const {return NULL;}
	virtual CPoint getAllowedPosBottomRight()const { return NULL; }
};

