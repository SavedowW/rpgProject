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
#define DRAWHBOX

class MapLevel :
    public Level
{
public:
    vector<Vector2> spawnPoints;

    std::vector<hitbox*> staticSolidMap;
    std::vector<Object*> staticObjects;
    std::vector<Object*> activeObjects;
    std::vector<InteractiveObject*> interactiveObjects;
    std::vector<LeavePoint*> staticLeavePoints;
    std::vector<Chest*> chests;
    std::vector<Trigger*> staticTriggerList;
    static std::vector<AnimatedTexture*> *textureList;

    Chest* currentChest;

    MapLevel(const Vector2 &nLvlSize, const Vector2 &nCamSize, int nLevelId, GameCore::Music nTheme);

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

    static const int SCENEINTSNUMBER = 10;
    int* sceneInt[SCENEINTSNUMBER];
    //sceneInt[0] is for any scene initialization
    //1 - SCENEINTSNUMBER - for local scene stuff

protected:
    virtual void renderLevel();
    virtual void processInput(const SDL_Event& e);
    virtual void movePlayer();
    virtual void uniqueLogic();
    virtual void beginBattle(Enemy* enemy, int battleId);
    virtual void beginBattleInstantly(Enemy* enemy, int battleId);
    virtual void updCam();
    virtual void localDefInputControls(const SDL_Event& e);

    GameCore::Music musTheme;

    virtual void pushMessage(const vector<vector<string>>& multilines, int font, int nPeriod, int nLinePeriod, int voiceId);
    void pushQuestionMultiselect(vector<string>* options, int** nTarget);

    enum LevelState {ENTER, RUN, LEAVE} state;
    static LevelHUD* levelHud;

    SDL_Texture* spr_idle;
};