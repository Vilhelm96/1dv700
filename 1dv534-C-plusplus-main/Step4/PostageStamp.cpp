/******************************************************
* File:         PostageStamp.cpp
* Description:  This is the file that handles the item.
*				All the functions are basically the same
*				as the album so won't comment on them.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize the comments	Vilhelm Park
*
******************************************************/

#include "PostageStamp.h"

void PostageStamp::show() 
{
	View view;
	view.println("Postage Stamp - " + _title + " - " + _releaseYear + " - " + _note);
}

const string PostageStamp::toString() const
{
	string tempPostageStamp = "PostageStamp--" + _title + "--" + _releaseYear + "--" + _note + "\n";
	return tempPostageStamp;
}

void PostageStamp::createItem()
{
	View view;
	string itemInformation[4];
	view.print("Write a title: ");
	view.write(itemInformation[1]);
	view.print("Write a release year: ");
	view.write(itemInformation[2]);
	view.print("Write a note: ");
	view.write(itemInformation[3]);
	loadInformation(itemInformation);
}

void PostageStamp::updateInformation()
{
	View view;
	int option;
	string updateInformation;

	view.print("Choose what information to change!\n1. Title: " + _title + "\n2. Release year: " + _releaseYear + "\n3. Note: " + _note + "\n4. Change nothing\nChoice: ");

	do
	{
		view.write(option);
		option -= 48;
	} while (option < 1 || option > 4);

	switch (option)
	{
	case 1:
		view.print("You choose to change the title for the item, input new title: ");
		view.write(updateInformation);
		setTitle(updateInformation);

		break;
	case 2:
		view.print("You choose to change the release year for the item, input new release year: ");
		view.write(updateInformation);
		setReleaseYear(updateInformation);

		break;
	case 3:
		view.print("You choose to change the note for the item, input new note: ");
		view.write(updateInformation);
		setNote(updateInformation);

		break;
	case 4:
		view.println("You choose to not change anything.");

		break;		

	default:
		view.printError("Something is not working as it should.");

		break;
	}
}

void PostageStamp::loadInformation(string values[])
{
	setTitle(values[1]);
	setReleaseYear(values[2]);
	setNote(values[3]);
}
