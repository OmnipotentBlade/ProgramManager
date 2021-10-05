#pragma once
#include <iostream>
#include <vector>

using namespace std;

int programmanager()
{
	double version = 0.02;
	int categorychoice;
	std::vector<std::string> games_program_list = { "RPG Game" };
	std::vector<std::string> tools_program_list = { "Password Manager" };
	std::vector<std::string> calcs_program_list = { "F to C Temperature Converter", "NYC Tax Calculator" };
	int allprograms = tools_program_list.size() + calcs_program_list.size() + games_program_list.size();
	
	std::cout << "Welcome to the Program Manager v" << version << "!\nHere you can launch multiple programs consisting of games, tools, and calculators.\n";
	std::cout << "(" << allprograms << ")" << " programs loaded\n\n";
	std::cout << "Which category of programs do you wish to load?\n\n  1) Games\n  2) Tools\n  3) Calculators & Converters\n\n";
	std::cout << "Please enter your choice.\n";
	std::cin >> categorychoice;

	while (categorychoice != 1 && categorychoice != 2 && categorychoice != 3)
	{
		std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
		std::cin >> categorychoice;
	}

	if (categorychoice == 1) //Launches Games Submenu in Program Manager
	{
		system("cls");
		int gameschoice;
		std::cout << "\nProgram Manager: Games\n\nWhich program do you wish to load?\n";
		std::cout << "  1) " << games_program_list[0] << "\n\n" << "  0) Go Back\n\n" << "Please enter your choice.\n";
		std::cin >> gameschoice;

		while (gameschoice != 0 && gameschoice != 1)
		{
			std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
			std::cin >> gameschoice;
		}

		if (gameschoice == 0)
		{
			system("cls");
			return(1000); //returns 1000 which allows main() in main.cpp to be called, thus successfully restarting the entire program
		}
		else if (gameschoice == 1)
		{
			string answer;
			std::cout << "Do you wish to load " << games_program_list[0] << "? (Y/N)\n";
			std::cin >> answer;

			while (answer != "Y" && answer != "N" && answer != "y" && answer != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> answer;
			}

			if (answer == "Y" || answer == "y")
			{
				system("cls");
				return(1);
			}

			else if (answer == "N" || answer == "n")
			{
				system("cls");
				return(1000);
			}
		}
	}

	if (categorychoice == 2) //Launches Tools Submenu in Program Manager
	{
		int toolschoice;
		system("cls");
		std::cout << "\nProgram Manager: Tools\n\nWhich program do you wish to load?\n";
		std::cout << "  1) " << tools_program_list[0] << "\n\n" << "  0) Go Back\n\n" << "Please enter your choice.\n";
		std::cin >> toolschoice;

		while (toolschoice != 0 && toolschoice != 1)
		{
			std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
			std::cin >> toolschoice;
		}

		if (toolschoice == 0)
		{
			system("cls");
			return(1000);
		}

		else if (toolschoice == 1)
		{
			string answer;
			std::cout << "Do you wish to load " << tools_program_list[0] << "? (Y/N)\n";
			std::cin >> answer;

			while (answer != "Y" && answer != "N" && answer != "y" && answer != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> answer;
			}

			if (answer == "Y" || answer == "y")
			{
				system("cls");
				return(2);
			}

			else if (answer == "N" || answer == "n")
			{
				system("cls");
				return(1000);
			}
		}

	}

	else if (categorychoice == 3) //Launches Calcs&Converters Submenu in Program Manager
	{
		int calcschoice;
		system("cls");
		std::cout << "\nProgram Manager: Calculators & Converters\n\nWhich program do you wish to load?\n";
		std::cout << "  1) " << calcs_program_list[0] << "\n  2) " << calcs_program_list[1] << "\n\n  0) Go Back";
		std::cout << "\n\nPlease enter your choice.\n";
		std::cin >> calcschoice;

		while (calcschoice != 0 && calcschoice != 1 && calcschoice != 2)
		{
			std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
			std::cin >> calcschoice;
		}

		if (calcschoice == 0)
		{
			system("cls");
			return(1000);
		}

		else if (calcschoice == 1)
		{
			string answer;
			std::cout << "Do you wish to load " << calcs_program_list[0] << "? (Y/N)\n";
			std::cin >> answer;

			while (answer != "Y" && answer != "N" && answer != "y" && answer != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> answer;
			}

			if (answer == "Y" || answer == "y")
			{
				system("cls");
				return(3);
			}

			else if (answer == "N" || answer == "n")
			{
				system("cls");
				return(1000);
			}
		}

		else if (calcschoice == 2)
		{
			string answer;
			std::cout << "Do you wish to load " << calcs_program_list[1] << "? (Y/N)\n";
			std::cin >> answer;
			while (answer != "Y" && answer != "N" && answer != "y" && answer != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> answer;
			}
			if (answer == "Y" || answer == "y")
			{
				system("cls");
				return(4);
			}
			else if (answer == "N" || answer == "n")
			{
				system("cls");
				return(1000);
			}
		}
	}
	//return(0);
	//TO-DO: 1) Turn this program into the main cpp file so that other headers can work properly with it. 2) Add a category called "Games" and put RPG in it
	/*INSTRUCTIONS FOR ADDING PROGRAM: 1) Add category for it if needed. 2) Add program to correct category vector. 3) If a new vector was created add the size
	of it to the "allprograms" variable. 4) Add corresponding return value to signal to main.cpp that the program needs to be launched 5) In main.cpp add an if
	statement that launches the desired program if a return value is equal to what is set.*/
}