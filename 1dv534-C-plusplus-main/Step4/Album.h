/******************************************************
* File:         Album.h
* Description:  This is the header that handles the 
*				Album.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef ALBUM_H
#define ALBUM_H

#include "BasicItem.h"
#include "View.h"
#include <string>
using std::string;

class Album : public BasicItem
{
public:
	//Change constructor to default at the end.
	Album() = default;
	virtual ~Album() {}
	void show() override;
	const string toString() const override;
	int getItemType() const { return _itemType; }
	string getTitle() const override { return _title; }
	void setTitle(string title) override { _title = title; }
	void createItem() override;
	void updateInformation() override;
	void loadInformation(string values[]) override;

	string getReleaseYear() { return _releaseYear; }
	string getGroup() { return _group; }
	string getGenre() { return _genre; }

	void setReleaseYear(string releaseYear) { _releaseYear = releaseYear; }
	void setGroup(string group) { _group = group; }
	void setGenre(string genre) { _genre = genre; }

private:
	item _itemType = album;
	string _title;
	string _releaseYear;
	string _group;
	string _genre;
};

/*********************************************************************
* Description: This comparator sorts the release year.
* Pre: Unsorted release year
* Post: Sorted release year
* Parameters: The two items that will get compared
* Returns:     
*********************************************************************/
class AlbumReleaseYearComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		Album *a_album = dynamic_cast<Album*>(a);
		Album *b_album = dynamic_cast<Album*>(b);

		if (a_album != nullptr && b_album != nullptr) {
			return a_album->getReleaseYear().compare(b_album->getReleaseYear());
		}
		else
		{
			view.printError("Could not cast the basic items into album. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};

/*********************************************************************
* Description: This comparator sorts the group.
* Pre: Unsorted group
* Post: Sorted group
* Parameters: The two items that will get compared
* Returns:
*********************************************************************/
class AlbumGroupComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		Album *a_album = dynamic_cast<Album*>(a);
		Album *b_album = dynamic_cast<Album*>(b);

		if (a_album != nullptr && b_album != nullptr) {
			return a_album->getGroup().compare(b_album->getGroup());
		}
		else
		{
			view.printError("Could not cast the basic items into album. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};

/*********************************************************************
* Description: This comparator sorts the genre.
* Pre: Unsorted genre
* Post: Sorted genre
* Parameters: The two items that will get compared
* Returns:
*********************************************************************/
class AlbumGenreComparator
{
public:
	bool operator()(BasicItem *a, BasicItem *b) 
	{
		View view;
		Album *a_album = dynamic_cast<Album*>(a);
		Album *b_album = dynamic_cast<Album*>(b);

		if (a_album != nullptr && b_album != nullptr) {
			return a_album->getGenre().compare(b_album->getGenre());
		}
		else
		{
			view.printError("Could not cast the basic items into album. Exiting!");
			exit(EXIT_FAILURE);
		}
	}
};
#endif 