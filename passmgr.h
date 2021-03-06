#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <chrono>

#include "programmgr.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

string passwordentry() //Password Data Entry Code
{
	string Input;
	string passcorrect;
	std::cout << "\nPlease enter the Password you wish to store.\n\nPassword: ";
	std::cin >> Input;
	std::cout << "\n\n\"" << Input << "\" Is this Password correct? (Y/N)\n";
	std::cin >> passcorrect;

	while (passcorrect != "Y" && passcorrect != "N" && passcorrect != "y" && passcorrect != "n")
	{
		std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
		std::cin >> passcorrect;
	}

	if (passcorrect == "Y" || passcorrect == "y")
	{
		return(Input);
	}
	else if (passcorrect == "N" || passcorrect == "n")
	{
		system("cls");
		string passwordentry();
	}

	//return("0");
}

string newdataentry() //Main Username + Password Data Entry Code
{
	system("cls");
	string UsernameInput;
	string PasswordInput;
	string usercorrect;
	std::cout << "\nPassword Manager: Username and Password New Entry\n\n" << "Please enter the Username you wish to store.\n\nUsername/Email: ";
	std::cin >> UsernameInput;
	std::cout << "\n\n\"" << UsernameInput << "\" Is this Username/Email correct? (Y/N)\n";
	std::cin >> usercorrect;

	while (usercorrect != "Y" && usercorrect != "N" && usercorrect != "y" && usercorrect != "n")
	{
		std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
		std::cin >> usercorrect;
	}

	if (usercorrect == "Y" || usercorrect == "y")
	{
		PasswordInput = passwordentry();
		string Credentials = UsernameInput + " " + PasswordInput;

		return(Credentials);
	}
	else if (usercorrect == "N" || usercorrect == "n")
	{
		system("cls");
		newdataentry();
	}

	//return("0");
}

bool filecheck()
{
	if (std::filesystem::exists("passfile.txt") == true)
	{
		return(true);
	}
	else if (std::filesystem::exists("passfile.txt") == false) //Sequence for if "passfile.txt" (file where usernames+passwords are stored) doesn't exist (first-time setup)
	{
		string filename = "passfile.txt";
		string choice;
		std::cout << "Initial password database file not found. Would you like to create one now? (Y/N)\n";
		std::cin >> choice;

		while (choice != "Y" && choice != "N" && choice != "y" && choice != "n")
		{
			std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
			std::cin >> choice;
		}

		if (choice == "Y" || choice == "y")
		{
			ofstream passtxt("passfile.txt");
			passtxt << "Password Manager v0.01\n" << "Usernames/Passwords:\n";
			passtxt.close();
			std::cout << "\nPassword database file created!" << " (\"" << filename << "\")\n";
			sleep_for(2s);
			
			return(false);
		}
		else if (choice == "N" || choice == "n")
		{
			string choice;
			std::cout << "Return to Program Manager? (Y/N)\n";
			std::cin >> choice;

			while (choice != "Y" && choice != "N" && choice != "y" && choice != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> choice;
			}

			if (choice == "Y" || choice == "y")
			{
				system("cls");
				programmanager();
			}
			else if (choice == "N" || choice == "n")
			{
				system("cls");
				filecheck();
			}
		}
	}
}

int passwordmgr()
{
	string filename = "passfile.txt";
	std::cout << "Welcome to the Password Manager v0.01!\nHere you can store and retrieve usernames and passwords all in one place.\n\n";
	bool fileexists = filecheck();

	if (fileexists == true) //Sequence for if "passfile.txt" (file where usernames+passwords are stored) does exist
	{
		std::cout << "Password database file detected! (\"passfile.txt\")\n\n";
		std::cout << "Which action do you wish to take?\n\n" << "  1) Create New Username + Password Entry\n  2) View Usernames and Passwords\n  3) Delete Username + Password Database File (" << filename << ")\n\n  0) Return to Program Manager\n\nPlease enter your choice.\n";
		int choice;
		std::cin >> choice;

		while (choice != 1 && choice != 2 && choice != 3 && choice != 0)
		{
			std::cout << "Invalid input. Please enter a number corresponding to your choice.\n";
			std::cin >> choice;
		}

		if (choice == 1) //Launches Username + Password Data Entry Function, Gets Data, Then Stores Data in "passfile.txt"
		{
			string UserPass = newdataentry();

			ofstream passtxt{ "passfile.txt", ios::app };
			passtxt << "\n" << UserPass;
			passtxt.close();

			system("cls");
			
			std::cout << "\nPassword Manager: Username and Password New Entry\n\nUsername/Password Combo:\n\n" << UserPass << "\n\n\nSUCCESS: Username/Password saved to database!";
			sleep_for(4s);
			system("cls");
			passwordmgr();
			//debuggingstd::cout << UserPass;
		}
		else if (choice == 2) //Opens "passfile.txt" in its own window using Notepad then when the .txt file is closed returns to the start of passwordmgr
		{
			std::cout << "\nOpening \"passfile.txt\"...\nUsername/Password database file \"passfile.txt\" is open!\n\nPlease close \"passfile.txt\" if you wish to return to Password Manager.";
			system("notepad ./passfile.txt");
			system("cls");
			passwordmgr();
		}
		else if (choice == 3) //Deletes "passfile.txt" from the directory it was created in
		{
			system("cls");
			std::cout << "\nPassword Manager: Database File Deletion\n\n-----------------------------------------------------------------------------------------------------------------------\nWARNING: This feature is mainly for debugging purposes. Only proceed if you wish to clear all your Usernames/Passwords.\n-----------------------------------------------------------------------------------------------------------------------\n\nAre you sure you wish to delete the Username/Password Database File \"" << filename << "\"? (Y/N)\nThis cannot be undone!\n";
			string choice;
			std::cin >> choice;

			while (choice != "Y" && choice != "N" && choice != "y" && choice != "n")
			{
				std::cout << "Invalid input. Please enter Y(Yes) or N(No).\n";
				std::cin >> choice;
			}

			if (choice == "Y" || choice == "y")
			{
				std::cout << "\nDeleting " << filename << "...\n\n";
				std::remove("passfile.txt");
				sleep_for(1s);
				std::cout << "File " << filename << " has been deleted.\n\n";
				sleep_for(2.5s);
				system("cls");
				passwordmgr();
			}
			else if (choice == "N" || choice == "n")
			{
				system("cls");
				passwordmgr();
			}
		}
		else if (choice == 0)
		{
			system("cls");
			programmanager();
		}

	}
	else if (fileexists == false)
	{
		system("cls");
		passwordmgr();
	}

	return(0);
	//TO-DO: 1) Finish code for choice == 1 and choice == 2 by adding a new entry interface and opening the .txt file to view usernames and passwords until
	//an actual reader within the program is created. 2) Encrypt any usernames and passwords that are stored. 3) Find a way to take the return strings from
	//newdataentry() and store it in a variable in the main program so that it can be stored in passfile.txt as an entry. 4) (Not a priority) Add a secure
	//random password generator.
}