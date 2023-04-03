/******************************************************
* File:         TemperatureMain.cpp
* Description:  This file use the classes 
*				TemperatureMenu and TemperatureOptions
*				to read the templog textfile and 
*				store the values inside it. Then
*				the user can choose what to do between
*				seeing all values, getting highest
*				and lowest values, get average of all
*				values or just quit the program.

* Version:      1.0    2020-04-01, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************/
#include "TemperatureMenu.h"
#include "TemperatureOptions.h"

int main()
{
	TemperatureMenu tempMenu;
	TemperatureOptions tempOptions("templog.txt", 24);
	tempMenu.initialText();
	//Try loading temperatures into the pointer.
	try {
		tempOptions.loadTemperaturesIntoArray();
	}
	//Get exception if something goes wrong and then delete the pointer.
	catch (std::exception &e)
	{
		tempOptions.deleteData();
		cout << e.what();
		return 0;
	}

	//Loop that runs until user choose the quit option.
	while (tempOptions.getLoopStatus())
	{
		tempMenu.menuText();
		tempMenu.readInput();
		switch (tempMenu.getMenuChoice())
		{
		case '1':
			tempOptions.displayAllTemperatures();
			break;

		case '2':
			tempOptions.displayMinMaxTemperature();
			break;

		case '3':
			tempOptions.displayAverageTemperature();
			break;

		default:
			tempOptions.quit();
			break;
		}
		cin.get();
	}
	//Delete the pointer.
	return 0;
}