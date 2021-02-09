#pragma once
#include "Level.h"
#include "BattleHUD.h"
#include "BackgroundsH.h"

enum class BattleCharacter { PLAYER, ENEMY };

class BattleLevel :
    public Level
{
public:
    BattleLevel(int nLevelId);

    virtual void enter(int entrance);
    virtual LevelResult levelProcess();

protected:
    virtual void processInput(const SDL_Event& e);
    virtual void renderLevel();

    void handleEnd();
    void handleEnter();

    void handlePlayerAction();
    void handlePlayerSkillParse();
    void handlePlayerEffects();

    void getEnemyAction();
    void handleEnemyAction();
    void handleEnemySkillParse();
    void handleEnemyEffects();

    void handleEffectFrom(BattleCharacter user, const Buff& effect);
    void handleEffectTo(BattleCharacter tar, const Buff& effect);

    enum LevelState { ENTER, RUN, END, LEAVE } state;
    enum BattleState {ENTERSTATE, PLAYERTURN, PLAYERSKILLPARSE, PLAYERTURNRES, PLAYERTURNEND, ENEMYTURN, ENEMYSKILLPARSE, ENEMYTURNRES, ENEMYTURNEND, RESULTS} battleState;

    Spell* currentSkill;
    int currentBuff; //For currentSkill effects

    int currentCharEffect; //For current character effects (DoT curse, regeneration, etc)

    BattleHUD* battleHud;

    CharacterAction* currentAction;

    Background* backgrounds[1];
};