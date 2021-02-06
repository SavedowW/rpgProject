#pragma once
#include "GameCore.h"
#include "ElementMessageBox.h"
#include "ElementBattleMessageBox.h"
#include "Player.h"
#include <functional>

class MessageHandler
{
public:
	static void itemMessage(int result, const string& name, int selected, ElementMessageBox* messageBox, Player* player);
	static void itemMessage(int result, const string& name, int selected, ElementBattleMessageBox* messageBox, Player* player);

private:

};