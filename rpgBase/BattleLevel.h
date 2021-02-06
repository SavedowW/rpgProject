#pragma once
#include "Level.h"
#include "BattleHUD.h"
#include "BackgroundsH.h"

class BattleLevel :
    public Level
{
public:
    BattleLevel();

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

protected:
    virtual void processInput(const SDL_Event& e);
    virtual void renderLevel();
    enum LevelState { ENTER, RUN, LEAVE, LEAVEBATTLE } state;
    enum BattleState {ENTERSTATE, PLAYERTURN, PLAYERSKILLPARSE, PLAYERTURNRES, PLAYERTURNEND, ENEMYTURN, ENEMYSKILLPARSE, ENEMYTURNRES, ENEMYTURNEND, RESULTS} battleState;

    Spell* currentSkill;
    int currentBuff;

    int currentCharEffect;

    BattleHUD* battleHud;

    CharacterAction* currentAction;

    Background* backgrounds[1];
};