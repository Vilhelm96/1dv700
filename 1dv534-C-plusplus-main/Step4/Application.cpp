/******************************************************
* File:         Application.cpp
* Description:  This is the file that puts all the other
*				classes together.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#include "Menu.h"

class Application
{
public:
	void run();

};

void Application::run()
{
	Menu menu;
	Registry *itemRegister = new Registry();
	itemRegister->loadReg("TestFile.txt");
	itemRegister->showAllItems();
	menu.theMenu(itemRegister);
	itemRegister->showAllItems();
	itemRegister->saveReg("TestFile.txt");
	itemRegister->~Registry();
}

int main()
{
	Application app;
	app.run();
	
	system("pause");
	return 0;
}