#include "Player.h"

int getLimitedInput(int lowerEdge, int higherEdge)
{
	int input;
	cin >> input;
	while (input < lowerEdge || input > higherEdge)
	{
		cout << "Wrong input! Please, try again\n";
		cin >> input;
	}
	return input;
}

bool proceedBattle(Player* player, Character* enemy)
{
	/*int step = -1;
	while (player->HP > 0 && enemy->HP > 0)
	{
		system("cls");
		step *= -1;
		cout << "HP | (you) " << player->HP << " / " << enemy->HP << " (" << enemy->name << ")\n";
		cout << "MP | (you) " << player->MP << " / " << enemy->MP << " (" << enemy->name << ")\n";
		if (step == 1)
		{
			//PLAYER'S STEP
			cout << "=== YOUR TURN ===\n";
			AttackResult act = player->stepAI();
			if (act.type == AttackResult::ATTACK) {
				int damage = enemy->receivePhysDamage(act.value);
				if (damage > 0)
					cout << "Physical attack! -" << damage << " HP\n";
				else
					cout << "Parry! 0 HP lost\n";
			} else if (act.type == AttackResult::BLOCK) {
				cout << "You've taken a block stand for a single round\n";
			} else if (act.type == AttackResult::SPELL) {
				cout << "You've used \"" << act.spell->name << "\"\n";
				if (player->MP > act.spell->cost) {
					player->MP -= act.spell->cost;
					cout << act.spell->battleDescr << endl;
					for (int i = 0; i < act.spell->effects.size(); i++)
					{
						switch (act.spell->effects[i].effect)
						{
						case (Buff::INSTANT_HP_RESTORE):
							cout << "You have restored " << player->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						case (Buff::INSTANT_MP_RESTORE):
							cout << "You have restored " << player->receiveEffect(act.spell->effects[i]) << " MP\n";
							break;
						case (Buff::INSTANT_MAGICAL_DAMAGE):
							cout << enemy->name << " have taken magical damage! -" << enemy->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						case (Buff::INSTANT_PHYSICAL_DAMAGE):
							cout << enemy->name << " have taken physical damage! -" << enemy->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						}
					}
				}
				else cout << "Since you have not enough MP, nothing happens...\n";
			} else if (act.type == AttackResult::ITEM) {
				switch (act.value)
				{
				case (0):
					cout << "You've wasted your precious time for nothing\n";
					break;

				case (1):
					cout << "You have equipped a new weapon\n";
					break;

				case (2):
					cout << "You have equipped a new armor\n";
					break;

				case (3):
					cout << "You have used this item\n";
					break;
				}
			}
			system("pause");
			

		} else {
			//ENEMIES STEP
			cout << "=== ENEMY'S TURN ===\n";
			AttackResult act = enemy->stepAI();
			if (act.type == AttackResult::ATTACK) {
				int damage = player->receivePhysDamage(act.value);
				if (damage > 0)
					cout << "Physical attack! -" << damage << " HP\n";
				else
					cout << "Parry! 0 HP lost\n";
			}
			else if (act.type == AttackResult::BLOCK) {
				cout << enemy->name << " have taken a block stand for a single round\n";
			}
			else if (act.type == AttackResult::SPELL) {
				cout << enemy->name << " have used \"" << act.spell->name << "\"\n";
				if (enemy->MP > act.spell->cost) {
					enemy->MP -= act.spell->cost;
					cout << act.spell->battleDescr << endl;
					for (int i = 0; i < act.spell->effects.size(); i++)
					{
						switch (act.spell->effects[i].effect)
						{
						case (Buff::INSTANT_HP_RESTORE):
							cout << enemy->name << " have restored " << enemy->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						case (Buff::INSTANT_MP_RESTORE):
							cout << enemy->name << " have restored " << enemy->receiveEffect(act.spell->effects[i]) << " MP\n";
							break;
						case (Buff::INSTANT_MAGICAL_DAMAGE):
							cout << "You've taken magical damage! -" << player->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						case (Buff::INSTANT_PHYSICAL_DAMAGE):
							cout << "You've taken physical damage! -" << player->receiveEffect(act.spell->effects[i]) << " HP\n";
							break;
						}
					}
				}
				else cout << "Since " << enemy->name << " have not enough MP, nothing happens...\n";
			}
			system("pause");


		}
	}*/
	if (player->HP > 0)
		return true;
	else
		return false;
}