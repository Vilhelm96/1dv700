/******************************************************
* File:         BasicItem.h
* Description:  This is the parent to the other items.
*				They will inherit the virtual functions.			
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef BASICITEM_H
#define BASICITEM_H

#include <string>
using std::string;

class BasicItem
{
public:

	//Enumeration for the different items.
	enum item
	{
		album = 0,
		plant = 1,
		postageStamp = 2
	};

	virtual ~BasicItem() = default;
	virtual int getItemType() const = 0;
	virtual string getTitle() const = 0;
	virtual void setTitle(string title) = 0;
	virtual void createItem() = 0;
	virtual void updateInformation() = 0;
	virtual void loadInformation(string values[]) = 0;
	virtual void show() = 0;
	virtual const string toString() const = 0;
};
/*********************************************************************
* Description: This comparator sorts the title.
* Pre: Unsorted title
* Post: Sorted title
* Parameters: The two items that will get compared
* Returns:
*********************************************************************/
class ItemComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) const
	{
		return a->getTitle().compare(b->getTitle());
	}
};
#endif 
