#pragma once
#include "GameCore.h"
#include "Player.h"
#include <functional>
#include "ElementMessageBox.h"

class MessageHandler
{
public:
	static void itemMessage(int result, Item* item, string name, int selected, ElementMessageBox* messageBox, Player* player);

private:

};