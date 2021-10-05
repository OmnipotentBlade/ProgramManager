#pragma once
#include <iostream>
#include <vector>

#include "programmgr.h"

using namespace std;

int rpg()
{
	int hp = 200;
	int enemyhp = 50;
	int gold = 500;
	int exit;
	int attackchoice;
	int heavystamina = 10;
	int normalstamina = 6;
	int lightstamina = 3;
	double stamina = 20.3;
	// ^ Variables that use a deciamal require the "double" variable declaration

	std::cout << "An enemy stares menacingly at you!\nEnemy HP: " << enemyhp << "\n";
	std::cout << "You have " << hp << " HP!\n" << "You have " << stamina << " stamina!\n" << "You have " << gold << " gold!\n";
	// ^ Chaining
	std::cout << "Which move will you use?\n  1) Heavy Attack\n  2) Normal Attack\n  3) Light Attack\n  4) Flee\n";
	std::cout << "Please input a number.\n";
	std::cin >> attackchoice;

	while (attackchoice != 1 && attackchoice != 2 && attackchoice != 3 && attackchoice != 4)
	{
		std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
		std::cin >> attackchoice;
	}

	switch (attackchoice)
	{
	case 1:
		std::cout << "You used Heavy Attack!\nDealt 50 damage!\n";
		enemyhp = enemyhp - 50;
		gold = gold + 200;
		stamina = stamina - heavystamina;
		std::cout << "Consumed 10 stamina!\n" << "You now have " << stamina << " stamina left!\n";
		std::cout << "Enemy has " << enemyhp << " HP left!\nYou defeated Enemy!\nEarned 200 Gold.\nGold: " << gold << "G\n";
		std::cin >> exit;
		break;
	case 2:
		std::cout << "You used Normal Attack!\nDealt 30 damage!\n";
		stamina = stamina - normalstamina;
		std::cout << "Consumed 6 stamina!\n" << "You now have " << stamina << " stamina left!\n";
		std::cin >> exit;
		break;
	case 3:
		std::cout << "You used Light Attack.\nDealt 15 damage...\n";
		stamina = stamina - lightstamina;
		std::cout << "Consumed 3 stamina.\n" << "You now have " << stamina << " stamina left!\n";
		std::cin >> exit;
		break;
	case 4:
		string retryanswer;
		std::cout << "You fled the battle.\nWhat a coward...\nYou were chased and backstabbed by the enemy.\n";
		gold = gold - gold;
		hp = hp - hp;
		std::cout << "You died and lost all your Gold.\n";
		std::cout << "You have " << gold << " gold remaining.\n";
		std::cout << "You have " << hp << " HP remaining.\nGame over.\n";
		std::cout << "Retry? (Y/N)\n";
		std::cin >> retryanswer;

		while (retryanswer != "Y" && retryanswer != "N" && retryanswer != "y" && retryanswer != "n")
		{
			std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
			std::cin >> retryanswer;
		}

		if (retryanswer == "Y" || retryanswer == "y")
		{
			system("cls");
			rpg();
		}
		else if (retryanswer == "N" || retryanswer == "n") {
			string retrynoconfirm;
			std::cout << "Are you sure you want to exit? (Y/N)\n";
			std::cin >> retrynoconfirm;

			while (retrynoconfirm != "Y" && retrynoconfirm != "N" && retrynoconfirm != "y" && retrynoconfirm != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> retrynoconfirm;
			}

			if (retrynoconfirm == "Y" || retrynoconfirm == "y")
			{
				string bootprgmmgr;
				std::cout << "(Optional) Boot into Program Manager? (Y/N)\n";
				std::cin >> bootprgmmgr;

				while (bootprgmmgr != "Y" && bootprgmmgr != "N" && bootprgmmgr != "y" && bootprgmmgr != "n")
				{
					std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
					std::cin >> bootprgmmgr;
				}

				if (bootprgmmgr == "Y" || bootprgmmgr == "y")
				{
					system("cls");
					programmanager();
				}
				else if (bootprgmmgr == "N" || bootprgmmgr == "n")
				{
					return(0);
				}
			}
			else if (retrynoconfirm == "N" || retrynoconfirm == "n")
			{
				system("cls");
				rpg();
			}
		}

		break;
	}
	
	return(0);
}
