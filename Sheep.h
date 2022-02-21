#pragma once
#include "Mammal.h"
#include <mmsystem.h>
#include <time.h>
class Sheep :
    public Mammal
{
    DECLARE_SERIAL(Sheep)
private:
    int _sound;
    int _Id = 0;
    int _trimLevel;
public:
    Sheep();
    CPoint getAllowedPosTopLeft()const;
    CPoint getAllowedPosBottomRight()const;
    int GetId()const;
    void draw(CDC* dc);
    int getPlay()const { return _trimLevel; }
    void makeNoise();
    void play();
    CPoint getCord() const;
    void setCord(CPoint cord);
};

