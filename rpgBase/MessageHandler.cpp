#include "MessageHandler.h"

void MessageHandler::itemMessage(int result, const string& name, int selected, ElementMessageBox* messageBox, Player* player)
{
	//Other
	if (result == 0)
		messageBox->pushMessages(
			{
					{"How do you expect me to use " + name + "?"}
			}, 5, 5, 10, 0
		);

	//Weapon
	else if (result == 1)
		messageBox->pushMessages(
			{
					{"You have equipped a new weapon!", player->inventory[selected]->name + " returned to your inventory."}
			}, 5, 5, 10, 0
		);

	//Armor
	else if (result == 2)
		messageBox->pushMessages(
			{
					{"You have equipped a new armor!", player->inventory[selected]->name + " returned to your inventory."}
			}, 5, 5, 10, 0
		);

	//Buffer
	else if (result == 3)
		messageBox->pushMessages(
			{
				{"You have used a " + name + "."}
			}, 5, 5, 10, 0
		);

	//Exthorium
	else if (result == 6)
		messageBox->pushMessages(
			{
				{"You have equipped a new weapon!", player->inventory[selected]->name + " returned to your inventory."},
				{"You have received a unique skill!", "\"Mystical blade\" will be available until you equip", "another weapon."}
			}, 5, 5, 10, 0
		);
}

void MessageHandler::itemMessage(int result, const string& name, int selected, ElementBattleMessageBox* messageBox, Player* player)
{
	//Other
	if (result == 0)
		messageBox->pushMessages(
			{
					{"How do you expect me to use " + name + "?"}
			}, 9, 5, 10, 0
		);

	//Weapon
	else if (result == 1)
		messageBox->pushMessages(
			{
					{"You have equipped a new weapon!", player->inventory[selected]->name + " returned to your inventory."}
			}, 9, 5, 10, 0
		);

	//Armor
	else if (result == 2)
		messageBox->pushMessages(
			{
					{"You have equipped a new armor!", player->inventory[selected]->name + " returned to your inventory."}
			}, 9, 5, 10, 0
		);

	//Buffer
	else if (result == 3)
		messageBox->pushMessages(
			{
				{"You have used a " + name + "."}
			}, 9, 5, 10, 0
		);

	//Exthorium
	else if (result == 6)
		messageBox->pushMessages(
			{
				{"You have equipped a new weapon!", player->inventory[selected]->name + " returned to your inventory."},
				{"You have received a unique skill!", "\"Mystical blade\" will be available until you equip another weapon."}
			}, 9, 5, 10, 0
		);
}