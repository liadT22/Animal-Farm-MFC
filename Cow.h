#pragma once
#include "Mammal.h"
#include <mmsystem.h>
#include <time.h>

class Cow :
    public Mammal
{
    DECLARE_SERIAL(Cow)
private:
    int _sound;
    int _Id = 1;
    bool _isMilk;
public:
    Cow();
    CPoint getAllowedPosTopLeft()const;
    CPoint getAllowedPosBottomRight()const;
    void play() { this->_isMilk = true; };
    int getPlay()const { return this->_isMilk; };
    void draw(CDC* dc);
    int GetId()const;
    void makeNoise();
    CPoint getCord() const;
    void setCord(CPoint cord);
};

