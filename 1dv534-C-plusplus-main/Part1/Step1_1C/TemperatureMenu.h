/******************************************************
* File:         TemperatureMenu.h
* Description:  Header for TemperatureMenu.
* Version:      1.0    2020-04-10, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************/
#include <iostream>

using std::cout;
using std::cin;

class TemperatureMenu
{	
private:
	//The variable for users choice in menu.
	char menuChoice;

public:
	//Function that output the initial text user will see.
	void initialText();
	//Function that output the menu.
	void menuText();
	//Function that reads the users input
	void readInput();
	//Getter for menuChoice.
	char getMenuChoice();
};
