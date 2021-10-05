#pragma once
#include <iostream>

#include "programmgr.h"

using namespace std;

int tempcalc()
{
	string convertagainchoice;
	double tempf;
	double tempc;

	std::cout << "Temperature Converter from Fahrenheit(F) to Celsius(C)\n";
	std::cout << "Please input temperature in Fahrenheit: ";
	std::cin >> tempf;

	tempc = (tempf - 32) / 1.8;

	std::cout << "The temperature is " << tempc << " degrees Celsius.\n\n";
	std::cout << "Convert again? (Y/N)\n";
	std::cin >> convertagainchoice;

	while (convertagainchoice != "Y" && convertagainchoice != "N" && convertagainchoice != "y" && convertagainchoice != "n")
	{
		std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
		std::cin >> convertagainchoice;
	}

	if (convertagainchoice == "Y" || convertagainchoice == "y")
	{
		system("cls");
		tempcalc();
	}

	else if (convertagainchoice == "N" || convertagainchoice == "n")
	{
		string prgmmgrchoice;
		std::cout << "Return to Program Manager? (Y/N)\n";
		std::cin >> prgmmgrchoice;

		while (prgmmgrchoice != "Y" && prgmmgrchoice != "N" && prgmmgrchoice != "y" && prgmmgrchoice != "n")
		{
			std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
			std::cin >> convertagainchoice;
		}

		if (prgmmgrchoice == "Y" || prgmmgrchoice == "y")
		{
			system("cls");
			return(23);
			//programmanager();
		}

		else if (prgmmgrchoice == "N" || prgmmgrchoice == "n")
		{
			system("cls");
			tempcalc();
		}
	}

	//TO-DO: Add return value when prgmgrchoice == "Y" so that bootloader(main.cpp) can boot into programmanager.

	return(0);
}