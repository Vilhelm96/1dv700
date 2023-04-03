/******************************************************
* File:         Menu.cpp
* Description:  This is the file handles the menu 
*				and the actions you can do from it.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#include "Menu.h"

/*********************************************************************
* Description:	This function creates the menu and handles the actions 
*				the users take in the menu.
* Pre:
* Post:
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Menu::theMenu(Registry *itemRegistry)
{
	View view;
	int choice;
	string answer;

	do {
		view.print("1. Add a item\n2. Remove item \n3. Remove all items \n4. Update item \n5. Show a item \n6. Show all items of a type \n7. Show all items \n8. Sort items in a type \n9. Exit application \nChoice: ");
		view.write(choice);
		choice -= 48;
		menuChoices(choice, itemRegistry);
	} while (choice != 9);
}

/*********************************************************************
* Description:	This function uses the Registry clas to do the actions
*				users makes.
* Pre:
* Post:
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Menu::menuChoices(int choice, Registry *itemRegistry)
{
	View view;
	string itemTitle;
	int itemType;
	int typeChoice;
	BasicItem *item;

	switch(choice)
	{ 
	case 1:
		item = whatItem();
		item->createItem();
		itemRegistry->addItem(item);
		itemRegistry->showAllItems();
		break;
	case 2:
		itemRegistry->showAllItems();
		item = whatItem();
		view.print("Title of item that you want to remove: ");
		view.write(itemTitle);
		item->setTitle(itemTitle);
		itemRegistry->removeItem(item);
		break;
	case 3:
		itemRegistry->emptyReg();
		view.println("All items got removed.");
		break;
	case 4:
		itemRegistry->showAllItems();
		item = whatItem();
		view.print("Title of item that you want to update: ");
		view.write(itemTitle);
		item->setTitle(itemTitle);
		itemRegistry->updateItem(item);
		break;
	case 5:
		view.print("Title of item that you want to update: ");
		view.write(itemTitle);
		itemRegistry->showAItem(itemTitle);
		break;
	case 6:
		view.print("What type of items do you want to see?\n1. Album \n2. Plant \n3. Postage Stamp \nChoice: ");
		
		do 
		{
			view.write(typeChoice);
			typeChoice -= 49;	//Puts - 49 instead of 48 since the function whatType in registry 
			// goes between 0-2 instead of 1-3.
		} while (typeChoice < 0 || typeChoice > 3);

		itemRegistry->showItemsOfOneType(typeChoice);
		break;
	case 7:
		itemRegistry->showAllItems();
		break;
	case 8:
		view.print("Choose what type you want to sort. \n1. Album \n2. Plant \n3. Postage stamp \nChoice:  ");

		do
		{
			view.write(itemType);
			itemType -= 49;
		} while (itemType < 0 || itemType > 2);

		if (itemType == 0)
		{
			view.print("Choose what information you want to sort. \n1. Title \n2. Release year \n3. Group \n4. Genre \nChoice:  ");

			do
			{
				view.write(choice);
				choice -= 49;
			} while (choice < 0 || choice > 3);
		}
		else if (itemType == 1)
		{
			view.print("Choose what information you want to sort. \n1. Title \n2. Latin title \n3. Note \nChoice:  ");
			do
			{
				view.write(choice);
				choice -= 49;
			} while (choice < 0 || choice > 2);
		}
		else
		{
			view.print("Choose what information you want to sort. \n1. Title \n2. Release year \n3. Note \nChoice:  ");
			do
			{
				view.write(choice);
				choice -= 49;
			} while (choice < 0 || choice > 2);
		}

		itemRegistry->sortItems(itemType, choice);
		break;
	case 9:
		view.println("Exits the application!");

		break;
	default:
		view.printError("Something went wrong here!");
		break;
	}
}

/*********************************************************************
* Description: This function returns correct item.
* Pre:
* Post:
* Parameters:
* Returns:     Returns the item the user wants.
*********************************************************************/
BasicItem * Menu::whatItem()
{
	View view;
	int choice;
	view.print("What item? \n1. Album \n2. Plant \n3. Postage stamp \nChoice: ");

	do
	{
		view.write(choice);
		choice -= 48;
	} while (choice < 1 || choice > 3);

	if (choice == 1)
	{
		return new Album();
	}
	else if (choice == 2)
	{
		return new Plant();
	}
	else
	{
		return new PostageStamp();
	}
}