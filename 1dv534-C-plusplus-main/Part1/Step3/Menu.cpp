/**********************************************************************
 File:		Menu.cpp  -  class that outputs menu
 Summary:	Class Menu can create your own menu and then output it.

 Version:	1.0 - 2020-04-12	- Linnéuuniversitetet
 Author:	Vilhelm Park, Linnéuuniversitetet
 --------------------------------------------------------------------
 Log:		2020-04-12	First iteration of menu class.
**********************************************************************/
#include "Menu.h"

/******************************************************************************
				theMenuContent ( )
				----------------
 Description:	This method outputs the menucontent

 Pre:			

 Post:			The menu content is ouput in console

 Parameters:	None

******************************************************************************/
void Menu::theMenuContent()
{
	for(int i = 0; i < size; i++)
	{
		cout << menuContent[i] << endl;
	}
}

/******************************************************************************
				readMenuChoice ( )
				----------------
 Description:	This method reads the users input and checks that the input is valid.

 Pre:			The menu has been output.

 Post:			The users input is stored in menuChoice.

 Parameters:	None

******************************************************************************/
void Menu::readMenuChoice()
{
	int menuChoiceToInt;
	cout << "Enter a choice between 1 and " << size << ": ";
	cin >> this->menuChoice;
	menuChoiceToInt = menuChoice - 48;
	while (menuChoiceToInt < 0 || menuChoiceToInt > size)
	{
		cout << "Enter a choice between 1 and " << size << ": ";
		cin >> this->menuChoice;
		menuChoiceToInt = menuChoice - 48;
	}
}

/******************************************************************************
				createMenuContent ( char menuContent[])
				----------------
 Description:	This method takes the char sequence from the parameter and 
				puts it in the menuContent array.

 Pre:			

 Post:			The menuContent array has added one more content.

 Parameters:	
 menuContent:	Char sequence for the content we want to add to the menuContent 
				array.

******************************************************************************/
void Menu::createMenuContent(char menuContent[])
{
	this->menuContent[this->size++] = menuContent;
}

/******************************************************************************
				getMenuChoice ( )
				----------------
 Description:	This method is a getter for menuChoice.

 Pre:

 Post:			The menuChoice is given.

 Parameters:	None

******************************************************************************/
char Menu::getMenuChoice()
{
	return menuChoice;
}

/******************************************************************************
				getMenuTitle ( )
				----------------
 Description:	This method is a getter for menuTitle.

 Pre:			

 Post:			The menuTitle is given.

 Parameters:	None

******************************************************************************/
const char* Menu::getMenuTitle()
{
	return menuTitle;
}

/******************************************************************************
				setMenuTitle (char title[] )
				----------------
 Description:	This method is a setter for menuTitle.

 Pre:			
 Post:			The menuTitle is set.

 Parameters:	
 title:		The title we want to have for the menu.

******************************************************************************/
void Menu::setMenuTitle(char title[])
{
	this->menuTitle = title;
}

/******************************************************************************
				printMenuTitle ( )
				----------------
 Description:	This method prints the menu title.

 Pre:			We have the title added already..

 Post:			The menu title is printed.

 Parameters:	None

******************************************************************************/
void Menu::printMenuTitle()
{
	cout<< getMenuTitle() << endl
		<< "---------------------------------" << endl
		<< "     What do you want to do?" << endl << endl;
}
