#include "pch.h"
#include "GoldFish.h"

#define GOLD_FISH_SIZE_X 60
#define GOLD_FISH_SIZE_Y 30

IMPLEMENT_SERIAL(GoldFish, CObject, 1)

GoldFish::GoldFish() :Fish(this->getAllowedPosBottomRight(), this->getAllowedPosTopLeft())
{
	this->_isPeeing = 0;
	srand(time(NULL));
	int random = rand() % 3;
	this->_sound = random;
}

void GoldFish::draw(CDC* dc)
{
	CPen blackPen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen peePen(PS_SOLID, 6, RGB(255, 255, 0));
	CBrush fishBrush(RGB(255, 215, 0));
	CPoint a = getCord();
	dc->SelectObject(&blackPen);
	dc->SelectObject(&fishBrush);
	int* tailPosX = getDistanceToTailX();
	int* tailPosY = getDistanceToTailY();
	POINT vertices[3];
	for (int j = 0; j < 3; j++) {
		vertices[j].x = a.x + tailPosX[j];
		vertices[j].y = a.y + tailPosY[j];
	}
	if (getPlay()) {
		dc->SelectObject(&peePen);
		dc->MoveTo(a);
		dc->LineTo(a.x - 3, a.y + 20);
		dc->SelectObject(&blackPen);
	}
	dc->Polygon(vertices, 3);
	dc->Ellipse(a.x, a.y, a.x + GOLD_FISH_SIZE_X, a.y + GOLD_FISH_SIZE_Y);
}

CPoint GoldFish::getAllowedPosTopLeft() const
{
	CPoint temp;
	temp.x = 370;
	temp.y = 20;
	return temp;
}

CPoint GoldFish::getAllowedPosBottomRight() const
{
	CPoint temp;
	temp.x = 700;
	temp.y = 250;
	return temp;
}

int GoldFish::GetId() const
{
	return this->_Id;
}

void GoldFish::makeNoise()
{
	switch (this->_sound) {
	case 0:PlaySound(L"objet_ds_eau2.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 1:PlaySound(L"s27.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 2:PlaySound(L"s19.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	}
}

CPoint GoldFish::getCord() const
{
	return Animal::getCord();
}

void GoldFish::setCord(CPoint cord)
{
	Animal::setCord(cord);
}