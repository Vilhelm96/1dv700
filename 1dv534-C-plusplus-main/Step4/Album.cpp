/******************************************************
* File:         Album.cpp
* Description:  This is the file that handles the Album
*				object.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#include "Album.h"

/*********************************************************************
* Description: This function show the albums values.
* Pre:
* Post:	Show the item values.
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Album::show() 
{
	View view;
	view.println("Album - " + _title + " - " + _releaseYear + " - " + _group + " - " + _genre);
}

/*********************************************************************
* Description: This function returns the values as a string.
* Pre:
* Post:
* Parameters:
* Returns:     A string with the values.
*********************************************************************/
const string Album::toString() const
{
	string tempAlbum =  "Album--" + _title + "--" + _releaseYear + "--" + _group + "--" + _genre + "\n";
	return tempAlbum;
}

/*********************************************************************
* Description: This function inserts the vales into the item.
* Pre:
* Post:	Create the album.
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Album::createItem()
{
	View view;
	string itemInformation [5];
	view.print("Write a title: ");
	view.write(itemInformation[1]);	//Starts from index 1 since index 0 is the type.
	view.print("Write a release year: ");
	view.write(itemInformation[2]);
	view.print("Write a group: ");
	view.write(itemInformation[3]);
	view.print("Write a genre: ");
	view.write(itemInformation[4]);
	loadInformation(itemInformation);
}

/*********************************************************************
* Description:	This function updates the information in the album.
* Pre:	Normal item
* Post:	Updated item
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Album::updateInformation()
{
	View view;
	int option;
	string updateInformation;

	view.print("Choose what information to change!\n1. Title: " + _title + "\n2. Release year: " + _releaseYear + "\n3. Group: " + _group + "\n4. Genre: " + _genre + "\n5. Change nothing\n Choice: ");
	
	do
	{
		view.write(option);
		option -= 48;
	} while (option < 1 || option > 5);
	
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
			view.print("You choose to change the group for the item, input new group: ");
			view.write(updateInformation);
			setGroup(updateInformation);

			break;
		case 4:
			view.print("You choose to change the genre for the item, input new genre: ");
			view.write(updateInformation);
			setGenre(updateInformation);

			break;

		case 5:
			view.println("You choose to not change anything.");

			break;

		default:
			view.printError("Something is not working as it should.");

			break;
	}
}

/*********************************************************************
* Description:	This function loads the item with information before 
*				it is uploaded to the item registry.
* Pre:
* Post:
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Album::loadInformation(string values[])
{
	setTitle(values[1]);
	setReleaseYear(values[2]);
	setGroup(values[3]);
	setGenre(values[4]);
}