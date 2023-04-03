/******************************************************  
* File:         miserable.cpp 
* Description:  This file reads the temperature values 
*				from the templog.txt then the user
*				can choose between viewing all 
*				temperatures, viewing lowest and 
*				highest temperature, viewing average
*				temperature or quit the program.
* Version:      1.0    2020-04-01, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet  
******************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::endl;
using std::setprecision;
using std::setw;
using std::ifstream;
using std::ios;

const char FILE_NAME[] = "templog.txt";
const int ALL_TEMPERATURES = 24;

void menuText();
void readInput(char &menuOption);
void loadTemperaturesIntoArray(double *temperatureArray);
void displayAllTemperatures(double *temperatureArray);
void displayMinMaxTemperature(double *temperatureArray);
void displayAverageTemperature(double *temperatureArray);
void quit(int &loopRunningTrueOrFalse);

int main()
{
	int loopRunningTrueOrFalse = 1;
	char menuOption;
	double *temperatureArray = new double[ALL_TEMPERATURES];
	
	cout << "\n\nTemperature Statistics\n----------------------\n" <<
		    "\nReading logged values for processing and presentation... "<<
			"\n\nPress Enter for menu: ";
	cin.get();

	//Try loading temperatures into the pointer.
	try {
		loadTemperaturesIntoArray(temperatureArray);
	}
	//Get exception if something goes wrong and then delete the pointer.
	catch (std::exception &e)
	{
		delete[] temperatureArray;
		cout << e.what();
		return 0;
	}

	//Loop that runs until user choose the quit option.
	while (loopRunningTrueOrFalse)
	{
		menuText();
		readInput(menuOption);
		switch (menuOption)
		{
			case '1':
				displayAllTemperatures(temperatureArray);
				break;

			case '2':
				displayMinMaxTemperature(temperatureArray);
				break;

			case '3':
				displayAverageTemperature(temperatureArray);
				break;

			default:
				quit(loopRunningTrueOrFalse);
				break;
		}
		cin.get();
	}
	//Delete the pointer.
	delete[] temperatureArray;
	return 0;
}


/***********************************************
* Description: This function outputs the menu.
* Pre:
* Post:	Shows the menu in the console.
* Parameters:
* Returns:     Nothing
**********************************************/
void menuText()
{
	system("cls");
	cout << "\n\nMENU\n----\n\n1. Display temperature values\n2. " <<
		"View maximum and minimum temperatures\n3. " <<
		"View average temperature\n4. Quit\n\nMake your choice: ";
}

/***********************************************
* Description: This function reads the input 
*			   from the user. When incorrect
*			   input read until user input is
*			   correct.
* Pre:
* Post:	Input is used to choose a option in the 
*		menu.
* Parameters:
* Returns:     Nothing
**********************************************/
void readInput(char &menuOption)
{
	cin.get(menuOption);
	/*
		To get character to integer we need to decrease with 48 since the ascii value from
		the character will give us incorrect integer if we don't. For example 2 will give us 50.
	*/
	int optionToInteger = menuOption - 48;
	while (optionToInteger < 1 || optionToInteger > 4)
	{
		menuText();
		cin.get(menuOption);
		optionToInteger = menuOption - 48;
	}
	cin.get();
}

/***********************************************
* Description: This function loads the 
*			   temperatures from the textfile 
*			   into a pointer.
*
* Pre:	The pointer that will be used to store
*		the temperatures are sent into the 
*		function.
*
* Post:	The pointer is filled with the 
*		temperatures.
*
* Parameters: In the parameter we have the 
*			  pointer that will be used to
*			  store the temperatures.
*
* Returns:     Nothing
**********************************************/
void loadTemperaturesIntoArray(double *temperatureArray)
{
	ifstream temperatureFile(FILE_NAME, ios::out);
	double nextDouble;
	int counterArray = 0;

	//If the file is not open show error message and exit the function.
	if (!temperatureFile.is_open())
	{
		cout << "There is some error in opening the temperature file, try again!";
		cin.get();
		return;
	}

	//Load value and input it in temperature array.
	while (temperatureFile >> nextDouble)
	{
		*temperatureArray++ = nextDouble;	
	}
	temperatureFile.close();
}

/***********************************************
* Description:	This function displays all 
*				temperatures from the textfile.
*
* Pre:	User choose to see all temperatures.
*
* Post:	The temperatures are shown in the
*		console.
*
* Parameters:	Pointer that will show the 
*				temperatures.
*
* Returns:     Nothing
**********************************************/
void displayAllTemperatures(double *temperatureArray)
{	
	cout << "\nDisplaying the latest 24 temperature values:\n\n";
	int counterInLoop;
	double temperatureValue;

	for (int counterInLoop = 0; counterInLoop < ALL_TEMPERATURES; counterInLoop++)
	{
		//Output temperatures until we have 6 values, then go to next row.
		if (counterInLoop % 6 == 0)
		{
			cout << endl;
		}

		temperatureValue = *temperatureArray++;
		cout << fixed << setprecision(2) << setw(8) << temperatureValue;
	}
}

/***********************************************
* Description:	This function shows the lowest
*				and highest temperatures.
*
* Pre:	User choose to see lowest and highest
*		temperatures.
*
* Post:	Lowest and highest temperature is shown
*		on the display.	

* Parameters:	The pointer that will be used to
*				to find the lowest and highest
*				temperatures.
*
* Returns:     Nothing
**********************************************/
void displayMinMaxTemperature(double *temperatureArray)
{
	cout << "\nCalculating the maximum and minimum temperature...\n";
	double max = 0, min = 0;
	int counterInLoop;
	double temperatureValue;
	//Initial highest and lowest value that will be used to compare in the loop.
	temperatureValue = *temperatureArray++;
	max = min = temperatureValue;

	for (int counterInLoop = 1; counterInLoop < 24; counterInLoop++)
	{
		temperatureValue = *temperatureArray++;

		//Save the max and min value.
		if (temperatureValue > max)
		{
			max = temperatureValue;
		}

		if (temperatureValue < min)
		{
			min = temperatureValue;
		}
	}

	cout << "\nMaximum temperature: " << fixed << setprecision(2) << max << " degrees Celcius\n";
	cout << "\nMinimum temperature: " << min << " degrees Celcius\n";
}

/***********************************************
* Description:	This function adds all 
*				temperatures and calculates the
*				average temperature. Then 
*				displays the value in the console.
*
* Pre:	User choose to see the average temperature.
*
* Post:	The average temperature is shown in the 
*		console.
*
* Parameters:	The pointer will be used to 
*				add the full sum into a double.
*
* Returns:		Nothing
**********************************************/
void displayAverageTemperature(double *temperatureArray)
{
	cout << "\nCalculating average temperature...\n";
	double temperatureValue, averageTemperature, totalTemperatureValue = 0.0;

	for (int counterInLoop = 0; counterInLoop < 24; counterInLoop++)
	{
		temperatureValue = *temperatureArray++;
		//Gather the total sum of the temperatures.
		totalTemperatureValue += temperatureValue;
	}

	//Get average temperature.
	averageTemperature = totalTemperatureValue / ALL_TEMPERATURES;
	cout << "\nAverage temperature: ";
	cout << fixed << setprecision(2) << averageTemperature << " degrees Celcius\n";
}

/***********************************************
* Description:	This function will change the
*				flag into false so we can exit
*				the while loop.
*
* Pre:	User choose to exit the program.
*
* Post:	Program is terminated.
*
* Parameters:	Flag for the while loop is set
*				to false.
*
* Returns:		 Nothing
**********************************************/
void quit(int &loopRunningTrueOrFalse)
{
	//Set the variable that determines if the while loop runs to false so we cancel the loop.
	loopRunningTrueOrFalse = 0;
	cout << "\n\nTerminating the program.";
}

