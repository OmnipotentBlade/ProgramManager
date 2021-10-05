#include <iostream>

#include "programmgr.h"
#include "rpggame.h"
#include "tempcalc.h"
#include "passmgr.h"
#include "taxcalc.h"

using namespace std;

int main()
{
	int returnvariable = programmanager();

	if (returnvariable == 1000)
	{
		main();
	}
	else if (returnvariable == 1)
	{
		rpg();
	}
	else if (returnvariable == 2)
	{
		int returnvar = passwordmgr();

		if (returnvar == 1000)
		{
			system("cls");
			main();
		}
	}
	else if (returnvariable == 3)
	{
		tempcalc();
	}
	else if (returnvariable == 4)
	{
		taxcalc();
	}

	return(0);
	//TO-DO: 1) Turn this program into the main cpp file so that other headers can work properly with it. 2) Add a category called "Games" and put RPG in it
	//3) Make this a main cpp file that boots .h programmanager and when user selects program in programmgr it will return a value that will make main cpp file
	//boot that program.
}