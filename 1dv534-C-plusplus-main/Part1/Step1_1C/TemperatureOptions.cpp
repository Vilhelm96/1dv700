/******************************************************
* File:         TemperatureOptions.cpp
* Description:  This file has functions that reads
*				the temperature values from the
*				templog.txt then some more functions
*				that can view all temperatures, 
*				viewing lowest and highest temperature, 
*				viewing average temperature or quit the 
*				program.
* Version:      1.0    2020-04-10, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************/
#include "TemperatureOptions.h"

/***********************************************
* Description:	Constructor for 
*				TemperatureOptions.
*
* Parameters:	The pointer that will be used to store
*				the file name and the amount of
*				temperatures in the file.
*
* Returns:     Nothing
**********************************************/
TemperatureOptions::TemperatureOptions(const char *fileName, int allTemperatures)
{
	this->fileName = fileName;
	this->allTemperatures = allTemperatures;
}

/***********************************************
* Description:	Getter for the private variable
*				loopStatus.
*
* Pre:	
*
* Post:	Gets the loopStatus variable.
*
* Parameters:
*
* Returns:	Returns the private variable
*			loopStatus.
**********************************************/
int TemperatureOptions::getLoopStatus()
{
	return loopStatus;
}

/***********************************************
* Description:	This function the pointer
*				temperatureData.
*
* Pre:	The pointer can still be used.
*
* Post:	The pointer is deleted.
*
* Parameters: 
*
* Returns:     Nothing
**********************************************/
void TemperatureOptions::deleteData()
{
	delete[] this->temperatureData;
}

/***********************************************
* Description:	This function sets loopStatus to
*				0 and deletes the pointer
*				temperatureData.
*
* Pre:	The program is in a endless loop.
*
* Post:	The pointer exit endless loop.
*
* Parameters: 
*
* Returns:     Nothing
**********************************************/
void TemperatureOptions::exitLoop()
{
	this->loopStatus = 0;
	TemperatureOptions::deleteData();
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
void TemperatureOptions::loadTemperaturesIntoArray()
{
	std::ifstream temperatureFile(fileName, std::ios::out);
	this->temperatureData = new double[allTemperatures];
	double nextDouble;
	int counter = 0;

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
		temperatureData[counter++] = nextDouble;
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

//TODO TRY TO SEE WHAT I NEED TO FIX
void TemperatureOptions::displayAllTemperatures()
{
	cout << "\nDisplaying the latest 24 temperature values:\n\n";
	int counterInLoop;
	double temperatureValue;

	for (int counterInLoop = 0; counterInLoop < allTemperatures; counterInLoop++)
	{
		//Output temperatures until we have 6 values, then go to next row.
		if (counterInLoop % 6 == 0)
		{
			cout << endl;
		}

		temperatureValue = temperatureData[counterInLoop];
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
void TemperatureOptions::displayMinMaxTemperature()
{
	cout << "\nCalculating the maximum and minimum temperature...\n";
	double max = 0, min = 0;
	int counterInLoop;
	double temperatureValue;
	//Initial highest and lowest value that will be used to compare in the loop.
	temperatureValue = temperatureData[0];
	max = min = temperatureValue;

	for (int counterInLoop = 1; counterInLoop < 24; counterInLoop++)
	{
		temperatureValue = temperatureData[counterInLoop];

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
void TemperatureOptions::displayAverageTemperature()
{
	cout << "\nCalculating average temperature...\n";
	double temperatureValue, averageTemperature, totalTemperatureValue = 0.0;

	for (int counterInLoop = 0; counterInLoop < 24; counterInLoop++)
	{
		temperatureValue = temperatureData[counterInLoop];
		//Gather the total sum of the temperatures.
		totalTemperatureValue += temperatureValue;
	}

	//Get average temperature.
	averageTemperature = totalTemperatureValue / allTemperatures;
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
void TemperatureOptions::quit()
{
	//Set the variable that determines if the while loop runs to false so we cancel the loop.
	TemperatureOptions::exitLoop();
	cout << "\n\nTerminating the program.";
}