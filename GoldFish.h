#pragma once
#include "Fish.h"
#include <mmsystem.h>
#include <time.h>
class GoldFish :
    public Fish
{
    DECLARE_SERIAL(GoldFish)
private:
    int _sound;
    int _Id = 2;
    bool _isPeeing;
public:
    GoldFish();
    void play() { this->_isPeeing = true; }
    int getPlay()const { return this->_isPeeing; }
    void draw(CDC* dc);
    CPoint getAllowedPosTopLeft()const;
    CPoint getAllowedPosBottomRight()const;
    int GetId()const;
    void makeNoise();
    CPoint getCord() const;
    void setCord(CPoint cord);
};

