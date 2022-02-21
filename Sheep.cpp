#include "pch.h"
#include "Sheep.h"

#define SHEEP_SIZE_X 100
#define SHEEP_SIZE_Y 50
#define SHEEP_HEAD_SIZE_X 50
#define SHEEP_HEAD_SIZE_Y 25
IMPLEMENT_SERIAL(Sheep, CObject, 1)

Sheep::Sheep() :Mammal(this->getAllowedPosBottomRight(),this->getAllowedPosTopLeft())
{
	srand(time(NULL));
	int random = rand() % 3;
	this->_sound = random;
	this->_trimLevel = random;
}

CPoint Sheep::getAllowedPosTopLeft() const
{
	CPoint temp;
	temp.x = 20;
	temp.y = 20;
	return temp;
}

CPoint Sheep::getAllowedPosBottomRight() const
{
	CPoint temp;
	temp.x = 350;
	temp.y = 250;
	return temp;
}

int Sheep::GetId() const
{
	return this->_Id;
}

void Sheep::draw(CDC* dc)
{
	CPoint a = getCord();
	CPen blackPen(PS_SOLID, 2, RGB(0, 0, 0));
	dc->SelectObject(&blackPen);
	CBrush sheep0Brush(RGB(120, 120, 120));
	CBrush sheep1Brush(RGB(160, 160, 160));
	CBrush sheep2Brush(RGB(200, 200, 200));
	CBrush sheep3Brush(RGB(240, 240, 240));
		if (getPlay() == 0) {
			dc->SelectObject(&sheep0Brush);
		}
		if (getPlay() == 1) {
			dc->SelectObject(&sheep1Brush);
		}
		if (getPlay() == 2) {
			dc->SelectObject(&sheep2Brush);
		}
		if (getPlay() == 3) {
			dc->SelectObject(&sheep3Brush);
		}
		dc->Ellipse(a.x, a.y, a.x + SHEEP_SIZE_X, a.y + SHEEP_SIZE_Y);
		a.x += getDistanceToHeadX();
		a.y += getDistanceToHeadY();
		dc->Ellipse(a.x, a.y, a.x + SHEEP_HEAD_SIZE_X, a.y + SHEEP_HEAD_SIZE_Y);
}

void Sheep::makeNoise()
{
	switch (this->_sound) {
	case 0:PlaySound(L"goat-bleet.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 1:PlaySound(L"sheep-bah1.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 2:PlaySound(L"sheep-lamb.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	}
}

void Sheep::play()
{
	if (_trimLevel < 3) {
		_trimLevel++;
	}
}

CPoint Sheep::getCord() const
{
	return Animal::getCord();
}

void Sheep::setCord(CPoint cord)
{
	Animal::setCord(cord);
}
