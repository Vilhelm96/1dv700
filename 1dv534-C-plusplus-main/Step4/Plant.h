/******************************************************
* File:         Plant.h
* Description:  This is the header for the plant item.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef PLANT_H
#define PLANT_H

#include "BasicItem.h"
#include "View.h"
#include <string>
using std::string;

class Plant : public BasicItem
{
public:
	Plant() = default;
	virtual ~Plant() {}
	void show() override;
	const string toString() const override;
	int getItemType() const { return _itemType; }
	string getTitle() const override { return _title; }
	void setTitle(string title) override { _title = title; }
	void createItem() override;
	void updateInformation() override;
	void loadInformation(string values[]) override;

	string getLatinTitle() { return _latinTitle; }
	string getNote() { return _note; }

	void setLatinTitle(string latinTitle) { _latinTitle = latinTitle; }
	void setNote(string note) { _note = note; }

private:
	item _itemType = plant;
	string _title;
	string _latinTitle;
	string _note;
};

class PlantLatinTitleComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		Plant *a_plant = dynamic_cast<Plant*>(a);
		Plant *b_plant = dynamic_cast<Plant*>(b);

		if (a_plant != nullptr && b_plant != nullptr) {
			return a_plant->getLatinTitle().compare(b_plant->getLatinTitle());
		}
		else
		{
			view.printError("Could not cast the basic items into plant. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};

class PlantNoteComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		Plant *a_plant = dynamic_cast<Plant*>(a);
		Plant *b_plant = dynamic_cast<Plant*>(b);

		if (a_plant != nullptr && b_plant != nullptr) {
			return a_plant->getNote().compare(b_plant->getNote());
		}
		else
		{
			view.printError("Could not cast the basic items into plant. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};
#endif 