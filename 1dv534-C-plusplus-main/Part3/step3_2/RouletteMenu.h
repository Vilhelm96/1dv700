#ifndef ROULETTEMENU_H
#define ROLETTEMENU_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class RouletteMenu
{
public:
	RouletteMenu();
	~RouletteMenu();
	int fullMenu();

private:
	void menu();
	char getInput();
	char input;
};
#endif