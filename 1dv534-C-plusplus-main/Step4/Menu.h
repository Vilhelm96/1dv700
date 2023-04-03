/******************************************************
* File:         Menu.h
* Description:  This is the header for the menu.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef MENU_H
#define MENU_H

#include "View.h"
#include "Registry.h"
#include "BasicItem.h"

class Menu 
{
public:
	Menu() = default;
	void theMenu(Registry *itemRegistry);
private:
	void menuChoices(int choice, Registry *itemRegistry);
	BasicItem *whatItem();
};

#endif