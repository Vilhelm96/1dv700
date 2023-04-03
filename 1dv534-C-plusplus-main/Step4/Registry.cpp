/******************************************************
* File:         Registry.cpp
* Description:  This is the that handles the registry
*				that stores the items.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#include "Registry.h"

Registry::Registry()
{
}

Registry::~Registry()
{
	emptyReg();
}

/*********************************************************************
* Description: This function adds a item to the registry.
* Pre:
* Post:
* Parameters: The parent to the items so that every item can be used here.
* Returns:     Nothing
*********************************************************************/
void Registry::addItem(BasicItem *item)
{
	int found = -1;
	string itemType = whatType(item->getItemType());

	for (int i = 0; i < itemRegister.size(); i++)
	{
		if (itemRegister[i].first.compare(itemType) == 0)
		{
			itemRegister[i].second.push_back(item);
			found = i;
		}
	}

	if (found == -1) 
	{
		addType(itemType);
		addItem(item); //Recursion
	}
}

/*********************************************************************
* Description: This function adds a item type if not already added.
* Pre:	No item type
* Post:	Added item type.
* Parameters: The name of the type to add.
* Returns:     Nothing
*********************************************************************/
void Registry::addType(string typeName)
{
	vector<BasicItem*> itemVector;
	pair < string, vector<BasicItem* > > typePair;
	typePair.first = typeName;
	typePair.second = itemVector;
	itemRegister.push_back(typePair);
}

/*********************************************************************
* Description: This function updates the information for the item.
* Pre:
* Post:
* Parameters:	Parent item to the items.
* Returns:     Nothing
*********************************************************************/
void Registry::updateItem(BasicItem *item)
{
	pair <int, int> positions;
	string answer;
	View view;
	string typeToFind = whatType(item->getItemType());

	if (findItem(typeToFind, item->getTitle()))
	{
		positions = findItemPosition(typeToFind, item->getTitle());
		BasicItem *tempItem = itemRegister[positions.first].second.at(positions.second);

		do
		{
			tempItem->updateInformation();
			tempItem->show();
			view.println("Wanna keep on changing information (Yes/No): ");
			view.write(answer);
		} while (answer == "Yes" || answer == "yes");

		showAllItems();
	}
}

/*********************************************************************
* Description: This function remove the item from the registry.
* Pre:
* Post:
* Parameters:	Parent for the items so every item can be used here.
* Returns:     Nothing
*********************************************************************/
void Registry::removeItem(BasicItem *item)
{
	View view;
	pair <int, int> positions;
	string typeToFind = whatType(item->getItemType());

	if (findItem(typeToFind, item->getTitle()))
	{
		positions = findItemPosition(typeToFind, item->getTitle());
		BasicItem *tempItem = itemRegister[positions.first].second.at(positions.second);
		view.print("Item that will be removed: ");
		tempItem->show();
		itemRegister[positions.first].second.erase(itemRegister[positions.first].second.begin() + positions.second);
		delete tempItem;
	}
}

/*********************************************************************
* Description:	This function looks if the item actually exist in the 
*				registry.
* Pre:
* Post:
* Parameters:
* Returns:     true if it exist and false if it does not exist.
*********************************************************************/
bool Registry::findItem(string itemType, string item) const
{
	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		if (itemRegister[typeCounter].first.compare(itemType) == 0)
		{
			for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
			{
				if (itemRegister[typeCounter].second.at(itemCounter)->getTitle().compare(item) == 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

/*********************************************************************
* Description: This function finds the position for the item in the registry.
* Pre:
* Post:
* Parameters:	The type to look for and the actual item to look for.
* Returns:     pair of ints that stands for the positions.
*********************************************************************/
pair <int, int> Registry::findItemPosition(string itemType, string item)
{
	pair <int, int> positions;

	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		if (itemRegister[typeCounter].first.compare(itemType) == 0)
		{
			for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
			{
				if (itemRegister[typeCounter].second.at(itemCounter)->getTitle().compare(item) == 0)
				{
					positions.first = typeCounter;
					positions.second = itemCounter;
					return positions;
				}
			}
		}
	}
	
	//Give pair -1 to show something is wrong.
	positions.first = -1;
	positions.second = -1;
	return positions;
}

/*********************************************************************
* Description: This function shows a item.
* Pre:
* Post:
* Parameters: Title for the item to show.
* Returns:     Nothing
*********************************************************************/
void Registry::showAItem(string title) 
{
	View view;

	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
		{
			if (itemRegister[typeCounter].second.at(itemCounter)->getTitle().compare(title) == 0)
			{
				itemRegister[typeCounter].second.at(itemCounter)->show();
				return;
			}
		}	
	}

	view.println("Could not find the item!");
}

/*********************************************************************
* Description: This function shows item of one type.
* Pre:
* Post:
* Parameters: Type to show.
* Returns:     Nothing
*********************************************************************/
void Registry::showItemsOfOneType(int type) 
{
	View view;
	string theType = whatType(type);

	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		if (itemRegister[typeCounter].first.compare(theType) == 0)
		{
			for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
			{
				itemRegister[typeCounter].second.at(itemCounter)->show();
			}
			return;
		}
	}

	view.println("Could not find the type!");
}

/*********************************************************************
* Description: This function shows all the items in the registry.
* Pre:
* Post:
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Registry::showAllItems()
{
	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
		{
			itemRegister[typeCounter].second.at(itemCounter)->show();
		}
	}
}

/*********************************************************************
* Description:	This function sorts the items in order. 
*				User can base the sort on whatever information there is
*				in the item such as the title, group or genre.
* Pre:
* Post:
* Parameters:	Type to sort and information that we want to base the sort of.
* Returns:     Nothing
*********************************************************************/
void Registry::sortItems(int type, int informationChoice)
{
	ItemComparator itemComparator;

	if (type == 0)
	{

		if (informationChoice == 0)
		{
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), itemComparator);
		}
		else if (informationChoice == 1)
		{
			AlbumReleaseYearComparator albumReleaseYearComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), albumReleaseYearComparator);
		}
		else if (informationChoice == 2)
		{
			AlbumGroupComparator albumGroupComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), albumGroupComparator);
		}
		else
		{
			AlbumGenreComparator albumGenreComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), albumGenreComparator);
		}

	}
	else if (type == 1)
	{
		if (informationChoice == 0)
		{
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), itemComparator);
		}
		else if (informationChoice == 1)
		{
			PlantLatinTitleComparator plantLatinComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), plantLatinComparator);
		}
		else
		{
			PlantNoteComparator plantNoteComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), plantNoteComparator);
		}
	}
	else
	{

		if (informationChoice == 0)
		{
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), itemComparator);
		}
		else if (informationChoice == 1)
		{
			PostageStampReleaseYearComparator postageStampReleaseYearComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), postageStampReleaseYearComparator);
		}
		else
		{
			PostageStampNoteComparator postageStampNoteComparator;
			sort(itemRegister[type].second.begin(), itemRegister[type].second.end(), postageStampNoteComparator);
		}

	}
}

/*********************************************************************
* Description: This function empties the registry.
* Pre:
* Post:
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Registry::emptyReg()
{
	
	for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
	{
		for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
		{
			BasicItem *tempItem = itemRegister[typeCounter].second.at(itemCounter);
			itemRegister[typeCounter].second.erase(itemRegister[typeCounter].second.begin() + itemCounter);
			delete tempItem;
		}
	}

	itemRegister.clear();
}

/*********************************************************************
* Description: This function saves the registry to a text file.
* Pre:
* Post:
* Parameters:	The text file to save to.
* Returns:     Nothing
*********************************************************************/
void Registry::saveReg(const char * file)
{
	std::ofstream os(file, std::ios::out);
	View view;

	if (!os.is_open())
	{
		view.printError("File can't be found.\n");
		return;
	}

	try 
	{
		//Input the items to the file.
		for (int typeCounter = 0; typeCounter < itemRegister.size(); typeCounter++)
		{

			for (int itemCounter = 0; itemCounter < itemRegister[typeCounter].second.size(); itemCounter++)
			{
				os << itemRegister[typeCounter].second.at(itemCounter)->toString();
			}

		}

		emptyReg();
	}
	catch (std::bad_alloc &error)
	{
		view.printError(error.what());
	}
	catch(...)
	{
		view.printError("Unknown error.");
	}
	
	os.close();
}

/*********************************************************************
* Description:	This function loads the items from the textfile into the 
*				registry.
* Pre:
* Post:	
* Parameters:	Text file that contains the items.
* Returns:     Nothing
*********************************************************************/
void Registry::loadReg(const char * file)
{
	//Make sure registry always are open before loading into it.
	std::ifstream ifs(file, std::ios::in);
	View view;
	string row;
	string parsedString;
	string itemValues[100];
	int position = 0;
	int counter = 0;
	bool eternalLoop = true;

	if (!ifs.is_open())
	{
		view.printError("File can't be found!\n");
		return;
	}

	try 
	{
		//Load a row into the registry
		while (std::getline(ifs, row))
		{
			//Parse the row to get the values for the item in a vector seperately.
			while (eternalLoop)
			{
				position = row.find('--');

				if (position == -1)
				{
					eternalLoop = false;
					position = row.size();
					parsedString = row.substr(0, position);
					itemValues[counter++] = parsedString;
				}
				else 
				{
					parsedString = row.substr(0, position);
					itemValues[counter++] = parsedString;
					row.erase(0, position + 2);
				}
				
			}

			loadAItem(itemValues);
			eternalLoop = true;
			counter = 0;
		}
		
	}
	catch (std::bad_alloc &error)
	{
		view.printError(error.what());
	}
	catch (...)
	{
		view.printError("Unknown error.");
	}

	ifs.close();
}

/*********************************************************************
* Description: This function returns what type the item has.
* Pre:
* Post:
* Parameters:	int that stands for the types.
* Returns:		String for the type
*********************************************************************/
string Registry::whatType(int type)
{
	View view;

	switch (type)
	{
		case 0:
			return "Album;";
		case 1:
			return "Plant;";
		case 2:
			return "PostageStamp;";
		default:
			view.printError("A item type that has not been added yet. The type is: " + type);
			break;
	}

	return NULL;
}

/*********************************************************************
* Description:	This function loads string array into a item and then
*				adds it to the registry.
* Pre:
* Post:
* Parameters:	string array with the information.
* Returns:     Nothing
*********************************************************************/
void Registry::loadAItem(string item[])
{
	//Put the type into a string use it to check what type of item to load in.
	string type = item[0];

	if (type == "Album")
	{
		BasicItem *album = new Album();
		album->loadInformation(item);
		addItem(album);
	}
	else if (type == "Plant")
	{
		BasicItem *plant = new Plant();
		plant->loadInformation(item);
		addItem(plant);
	}
	else if (type == "PostageStamp")
	{
		BasicItem *postageStamp = new PostageStamp();
		postageStamp->loadInformation(item);
		addItem(postageStamp);
	}
	else 
	{
		View view;
		view.printError("A item that is not registered has been entered. The items type is: " + type);
	}
}