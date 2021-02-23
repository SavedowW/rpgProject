#pragma once
#include "Level.h"
#include "ElementMenuVSelect.h"

class MainMenu :
    public Level
{
public:
    MainMenu(int nLevelId);

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

protected:
    virtual void renderLevel();
    virtual void processInput(const SDL_Event& e);

    ElementMenuVSelect *mainMenu;
    enum class Elements {
        NEWGAME = 0,
        LOADGAME,
        SETTINGS,
        QUIT,
        SIZE};


};