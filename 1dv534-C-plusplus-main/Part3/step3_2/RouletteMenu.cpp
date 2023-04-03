#include "RouletteMenu.h"

RouletteMenu::RouletteMenu() = default;

RouletteMenu::~RouletteMenu() = default;

void RouletteMenu::menu()
{
	cout << "1) Enter how much money a player should have from the beginning." << endl <<
			"2) Enter the number of rounds to play in Option 3." << endl <<
			"3) Play the specified number of rounds and present the results." << endl <<
			"4) Quit the program." << endl;
}

char RouletteMenu::getInput()
{
	char input;
	int inputToInt;
	cout << "Input option: ";
	cin >> input;
	inputToInt = (int)input - 48;

	while (inputToInt > 4 && inputToInt < 1)
	{
		cout << "Input option: ";
		cin >> input;
		inputToInt = (int)input - 48;
	}

	return inputToInt;
}

int RouletteMenu::fullMenu()
{
	menu();
	return getInput();
}
