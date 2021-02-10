//====================================
//
//      MapLevel.h
//      Interface for map levels
//      It's better to use it when you don't want to create something special
//
//====================================
#pragma once
#include "Level.h"
#include "LevelHUD.h"
//#define DRAWHBOX

class MapLevel :
    public Level
{
public:
    vector<Vector2> spawnPoints;

    std::vector<hitbox*> staticSolidMap;
    std::vector<Object*> staticObjects;
    std::vector<Object*> activeObjects;
    std::vector<LeavePoint*> staticLeavePoints;
    std::vector<Chest*> chests;
    std::vector<Trigger*> staticTriggerList;
    static std::vector<AnimatedTexture*> *textureList;

    Chest* currentChest;

    MapLevel(const Vector2 &nLvlSize, const Vector2 &nCamSize, int nLevelId);

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

    int* dialogueInt;

protected:
    virtual void renderLevel();
    virtual void processInput(const SDL_Event& e);
    virtual void movePlayer();
    virtual void uniqueLogic();
    virtual void beginBattle(Enemy* enemy, int battleId);
    virtual void beginBattleInstantly(Enemy* enemy, int battleId);



    virtual void pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);
    void pushQuestionMultiselect(vector<string>* options, int** nTarget);

    int timer;
    enum LevelState {ENTER, RUN, LEAVE, LEAVEBATTLE} state;
    static SDL_Texture* spr_transition;
    const int transitionPeriod = 30;
    static LevelHUD* levelHud;

    SDL_Texture* spr_idle;
};