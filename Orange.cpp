#include "pch.h"
#include "Orange.h"
#include "MFC project2Dlg.h"

#define ORANGE_SIZE 40

Orange::Orange()
{
	int i, j = 0, random;
	for (i = 0; i < 12; i++) {
		if (i >= 0 && i <= 3) {
			this->_cord[i].x = 972 + j * 70;
			this->_cord[i].y = 110;
			j++;
			if (i == 3) {
				j = 0;
			}
		}
		else if (i >= 4 && i <= 7) {
			this->_cord[i].x = 972 + j * 70;
			this->_cord[i].y = 220;
			j++;
			if (i == 7) {
				j = 0;
			}
		}
		else {
			this->_cord[i].x = 972 + j * 70;
			this->_cord[i].y = 330;
			j++;
		}
	}
	srand(time(NULL));
	for (i = 0; i < 6; i++) {
		random = rand() % 11;
		this->_isOrange[random] = 1;
	}
}

void Orange::draw(CDC* dc)
{
	for (int i = 0; i < 12; i++) {
		if (this->_isOrange[i]) {
			dc->Ellipse(_cord[i].x, _cord[i].y,_cord[i].x + ORANGE_SIZE, _cord[i].y + ORANGE_SIZE);
			dc->MoveTo(_cord[i].x + 20, _cord[i].y + 10);
			dc->LineTo(_cord[i].x + 20, _cord[i].y - 5);
		}
	}
}

long Orange::getCordX(int i) const
{
	return this->_cord[i].x;
}

long Orange::getCordY(int i) const
{
	return this->_cord[i].y;
}

int Orange::isOnOrange(const CPoint& point) const
{
	int i;
	for (i = 0; i < 12; i++) {
		if (this->_isOrange) {
			if ((point.x > _cord[i].x && point.y > _cord[i].y) && (point.x < _cord[i].x + 40 && point.y < _cord[i].y + 40)) {
				return i;
			}
		}
	}
	return -1;
}
void Orange::orangeIsPressed(int orangeIndex)
{
	int random, i;
		this->_isOrange[orangeIndex] = 0;
		srand(time(NULL));
		for (i = 0; i < 2; i++) {
			random = rand() % 12;
			if (random == orangeIndex) {
				random += 1;
			}
			this->_isOrange[random] = 1;
	}
}
