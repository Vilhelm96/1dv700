#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Menu {
public:
	void theMenuContent();	//Function where the menu content is output.
	void readMenuChoice();	//Function where user output their choice in the menu.
	void createMenuContent(char menuContent[]);	//Function where you can create your own menu content.
	char getMenuChoice();	//Getter for menu choice.
	const char* getMenuTitle();	//Getter for menu title.
	void setMenuTitle(char title[]);	//Function where you set the title for the menu.
	void printMenuTitle();	//Function where the title is printed.

private:
	char menuChoice;	//Value for the users choice in the menu.
	int size = 0;	//Current size of the menuContent array.
	char* menuContent[100];	//Array where the content of the menu is stored.
	char* menuTitle;	//Char sequence where the title is stored.
};

