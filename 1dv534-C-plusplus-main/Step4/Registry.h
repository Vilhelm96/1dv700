/******************************************************
* File:         Registry.h
* Description:  This is the header for the registry.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef Registry_H
#define Registry_H

#include "BasicItem.h"
#include "Album.h"
#include "Plant.h"
#include "PostageStamp.h"
#include "View.h"

#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

using std::vector;
using std::pair;
using std::sort;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Registry
{
public:
	Registry();

	~Registry();

	void addItem(int type);
	
	void addItem(BasicItem *item);

	void updateItem(int id);

	void updateItem(BasicItem *item);

	void removeItem(BasicItem *item);

	bool findItem(string itemType, string item) const;

	void showAItem(string title);

	void showItemsOfOneType(int type = -1);

	void showAllItems();

	void sortItems(int type, int informationChoice);

	void emptyReg();

	void saveReg(const char *file);

	void loadReg(const char *file);


private:
	void addType(string typeName);
	pair <int, int> findItemPosition(string itemType, string item);
	void loadAItem(string item[]);
	string whatType(int type);

	vector <pair <string, vector <BasicItem*>>> itemRegister;
	int registerSize = 0;
};
#endif 