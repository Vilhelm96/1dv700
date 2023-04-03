/******************************************************
* File:         TemperatureOptions.h
* Description:  Header for TemperatureOptions.
* Version:      1.0    2020-04-10, Linnéuniversitetet
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

class TemperatureOptions
{
private:
	//The variable for amount of temperatures in the textfile.
	int allTemperatures;
	//The variable for the file name.
	const char *fileName;
	//The pointer that will gather all the temperatures.
	double *temperatureData{nullptr};
	//The variable for the status of the loop, 1 if the loop should run 0 if it should stop.
	int loopStatus = 1;
	//Function that will give loopstatus 0 and trigger the exit of the loop.
	void exitLoop();

public:
	//Constructor
	TemperatureOptions(const char *fileName, int allTemperatures);

	//Getter for the private variable loopstatus.
	int getLoopStatus();
	//Function that will delete the pointer temperatureData.
	void deleteData();
	//Function that will load the temperature values into the pointer temperatureData.
	void loadTemperaturesIntoArray();
	//Function that will display all the temperatures in pointer temperatureData.
	void displayAllTemperatures();
	//Function that will display the highest and lowest temperatures in pointer temperatureData.
	void displayMinMaxTemperature();
	//Function that will display the average temperature in the pointer temperatureData.
	void displayAverageTemperature();
	//Function that will exit the program.
	void quit();
};