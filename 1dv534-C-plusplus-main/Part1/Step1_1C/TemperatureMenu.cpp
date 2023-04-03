/******************************************************
* File:         TemperatureMenu.cpp
* Description:  This file has functions output text 
*				such as menu and read input from user.
* Version:      1.0    2020-04-10, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************/
#include "TemperatureMenu.h"

/***********************************************
* Description:	This function outputs the text
*				before the menu.
* Pre:
* Post:	Outputs the initial text in the console.
* Parameters:
* Returns:     Nothing
**********************************************/
void TemperatureMenu::initialText()
{
	cout << "\n\nTemperature Statistics\n----------------------\n" <<
		"\nReading logged values for processing and presentation... " <<
		"\n\nPress Enter for menu: ";
	cin.get();
}

/***********************************************
* Description: This function outputs the menu.
* Pre:
* Post:	Shows the menu in the console.
* Parameters:
* Returns:     Nothing
**********************************************/
void TemperatureMenu::menuText()
{
	system("cls");
	cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. " <<
		"View maximum and minimum temperatures\n3. " <<
		"View average temperature\n4. Quit\n\nMake your choice: ";
}

/***********************************************
* Description: This function reads the input
*			   from the user. When incorrect
*			   input read until user input is
*			   correct.
* Pre:
* Post:	Input is used to choose a option in the
*		menu.
* Parameters:
* Returns:     Nothing
**********************************************/
void TemperatureMenu::readInput()
{
	cin.get(this->menuChoice);
	/*
		To get character to integer we need to decrease with 48 since the ascii value from
		the character will give us incorrect integer if we don't. For example 2 will give us 50.
	*/
	int optionToInteger = menuChoice - 48;
	while (optionToInteger < 1 || optionToInteger > 4)
	{
		menuText();
		cin.get(this->menuChoice);
		optionToInteger = menuChoice - 48;
	}
	cin.get();
}
/***********************************************
* Description:	This function is a getter for
*				menuChoice.
* Pre:
* Post:	Gets menuChoice.
* Parameters:
* Returns:     Returns the menuChoice.
**********************************************/
char TemperatureMenu::getMenuChoice()
{
	return menuChoice;
}
