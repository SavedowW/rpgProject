#pragma once
#include "Level.h"
#include "ElementMenuVSwitch.h"

class SettingsMenu :
    public Level
{
public:
    SettingsMenu(int nLevelId);

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

protected:
    virtual void renderLevel();
    virtual void processInput(const SDL_Event& e);

    ElementMenuVSwitch* mainMenu;
    ElementMenuVSwitch* fsMenu;
    ElementMenuVSwitch* resMenu;

    enum class MenuElements {
        FULLSCREEN,
        RESOLUTION,
        RETURNTOMM,
        SIZE
    };

    enum State {
        MAINMENU,
        FSCREEN,
        RESOLUTION
    } state;

    enum ResList {
        R640,
        R1280,
        R1600,
        R1920,
        R2560
    };
};