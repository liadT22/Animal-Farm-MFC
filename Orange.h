#pragma once
#include <time.h>
class Orange
{
private:
	CPoint _cord[12];
	bool _isOrange[12];
public:
	Orange();
	void draw(CDC* dc);
	long getCordX(int i) const;
	long getCordY(int i) const;
	bool getIsOrange(int i) const {return _isOrange[i]; }
	int isOnOrange(const CPoint& point) const;
	void orangeIsPressed(int orangeIndex);
};

