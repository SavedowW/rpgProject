#pragma once
#include "MapLevel.h"

class MapLevel2 :
    public MapLevel
{
public:

    MapLevel2(int nLevelId);
    virtual void uniqueLogic();
    virtual void updCam();
    virtual void localDefInputControls(const SDL_Event& e);

protected:
    Blader* blader;
    bool isPlayerFocused;
};
