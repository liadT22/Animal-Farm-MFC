#include "pch.h"
#include "Cow.h"

IMPLEMENT_SERIAL(Cow, CObject, 1)
#define COW_SIZE_X 120
#define COW_SIZE_Y 55
#define COW_HEAD_SIZE_X 55
#define COW_HEAD_SIZE_Y 30

Cow::Cow() :Mammal(this->getAllowedPosBottomRight(), this->getAllowedPosTopLeft())
{
	this->_isMilk = false;
	srand(time(NULL));
	int random = rand() % 3;
	this->_sound = random;
}

CPoint Cow::getAllowedPosTopLeft() const
{
	CPoint temp;
	temp.x = 20;
	temp.y = 270;
	return temp;
}

CPoint Cow::getAllowedPosBottomRight() const
{
	CPoint temp;
	temp.x = 350;
	temp.y = 500;
	return temp;
}

void Cow::draw(CDC* dc)
{
	CPoint a = getCord();
	CBrush cowBrush(RGB(165, 42, 42));
	CPen blackPen(PS_SOLID, 2, RGB(0, 0, 0));
	dc->SelectObject(&blackPen);
	CPen milkPen(PS_SOLID, 8, RGB(255, 255, 255));
	dc->SelectObject(&cowBrush);
	dc->Ellipse(a.x, a.y, a.x + COW_SIZE_X, a.y + COW_SIZE_Y);
	a.x += getDistanceToHeadX();
	a.y += getDistanceToHeadY();
	dc->Ellipse(a.x, a.y, a.x + COW_HEAD_SIZE_X, a.y + COW_HEAD_SIZE_Y);
	if (getPlay()) {
		dc->SelectObject(&milkPen);
		a.x -= getDistanceToHeadX() - 7;
		a.y += 15;
		dc->MoveTo(a);
		dc->LineTo(a.x - 3, a.y + 20);
		dc->SelectObject(&blackPen);
	}
}

int Cow::GetId() const
{
	return this->_Id;
}

void Cow::makeNoise()
{
	switch (this->_sound) {
	case 0:PlaySound(L"CowMoo.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 1:PlaySound(L"cow2.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 2:PlaySound(L"cow.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	}
}

CPoint Cow::getCord() const
{
	return Animal::getCord();
}

void Cow::setCord(CPoint cord)
{
	Animal::setCord(cord);
}