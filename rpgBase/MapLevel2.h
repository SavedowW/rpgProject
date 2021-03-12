#pragma once
#include "MapLevel.h"

class MapLevel2 :
    public MapLevel
{
public:

    MapLevel2(int nLevelId);
    virtual void uniqueLogic();

protected:
    Blader* blader;
};
