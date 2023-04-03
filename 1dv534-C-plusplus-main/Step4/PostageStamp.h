/******************************************************
* File:         PostageStamp.h
* Description:  This is the header for the postage stamp.
*
* Version:      1.0    2020-08-26, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments			Vilhelm Park
*
******************************************************/

#ifndef POSTAGESTAMPS_H
#define POSTAGESTAMPS_H

#include "BasicItem.h"
#include "View.h"
#include <string>
using std::string;

class PostageStamp : public BasicItem
{
public:
	PostageStamp() = default;
	virtual ~PostageStamp() {}
	void show() override;
	const string toString() const override;
	int getItemType() const { return _itemType; }
	string getTitle() const override { return _title; }
	void setTitle(string title) override { _title = title; }
	void createItem() override;
	void updateInformation() override;
	void loadInformation(string values[]) override;

	string getReleaseYear() { return _releaseYear; }
	string getNote() { return _note; }

	void setReleaseYear(string releaseYear) { _releaseYear = releaseYear; }
	void setNote(string note) { _note = note; };

private:
	item _itemType = postageStamp;
	string _title;
	string _releaseYear;
	string _note;
};

/*********************************************************************
* Description: This comparator sorts the release year.
* Pre: Unsorted release year
* Post: Sorted release year
* Parameters: The two items that will get compared
* Returns:
*********************************************************************/
class PostageStampReleaseYearComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		PostageStamp *a_postageStamp = dynamic_cast<PostageStamp*>(a);
		PostageStamp *b_postageStamp = dynamic_cast<PostageStamp*>(b);

		if (a_postageStamp != nullptr && b_postageStamp != nullptr)
		{
			return a_postageStamp->getReleaseYear().compare(b_postageStamp->getReleaseYear());
		}
		else
		{
			view.printError("Could not cast the basic items into a postage stamp. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};

/*********************************************************************
* Description: This comparator sorts the note.
* Pre: Unsorted note
* Post: Sorted note
* Parameters: The two items that will get compared
* Returns:
*********************************************************************/
class PostageStampNoteComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		PostageStamp *a_postageStamp = dynamic_cast<PostageStamp*>(a);
		PostageStamp *b_postageStamp = dynamic_cast<PostageStamp*>(b);

		if (a_postageStamp != nullptr && b_postageStamp != nullptr)
		{
			return a_postageStamp->getNote().compare(b_postageStamp->getNote());
		}
		else
		{
			view.printError("Could not cast the basic items into a postage stamp. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};
#endif 