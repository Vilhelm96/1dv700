/**********************************************************************/
// File:	FullAlphabetTimer.cpp
// Summary: This class will calculate the time it takes for at user to
//			input the alphabet. 

// Version:	Version 1.0 - 2020-04-22
// Owner:	Vilhelm Park 
// -------------------------------------------
// Log:	2020-04-21	Created the file. 
//		2020-04-22	Commented the file.
//		
/**********************************************************************/

#include "FullAlphabetTimer.h"

/*********************************************************************
* Description:	This function starts a timer when user hits enter
*				then user will attempt to write the full alphabet
*				in small letters. When the try is finished either the
*				time it took for the try is returned or a errormessage
*				is sent and the function calls itself.
*
* Pre:	User starts the application.
*
* Post:	The time for the try is returned.
*
* Parameters:
*
* Returns:	void
*********************************************************************/
void FullAlphabetTimer::run()
{
	MyTime start, finish, difference;
	cout << "When you are ready press the enter key to continue." << endl;

	// Not a pretty solution, but wanted to be able to input letters into the console and then when
	// user press enter, the timer starts.
	do
	{

	} while (cin.get() != '\n');

	start = returnCurrentTime();	//Time when the attempt is started.
	cout << "Input the english alphabet in small letters: ";
	cin.getline(this->input, alphabetLength, '\n');	//The attempt to input full alphabet in small letters.
	finish = returnCurrentTime();	//Time when the attempt is finished.
	difference = finish - start;	//Calculate the time it took for the attempt.
	comp = new Compare;	//Initialize the compare.

	if (comp->equal(input))	//Compare the input to the expected input. If it's equal output the attempt time. 
	{
		delete comp;	//Delete the compare pointer.
		cout << difference << endl;
		cin.get();
	}
	//If not equal output error message and call run function again to start over.
	else
	{
		delete comp;	//Delete the compare pointer.
		errorMessage();
		run();
	}
}

/*********************************************************************
* Description:	This function return the current time.
*
* Pre:	
*
* Post:	The current time is returned.
*
* Parameters:
*
* Returns:	The current time.
*********************************************************************/
MyTime FullAlphabetTimer::returnCurrentTime()
{
	clock = new Clock;
	MyTime myTime = clock->give_me_the_time();
	delete clock;	//Not needed anymore.
	return myTime;
}

/*********************************************************************
* Description:	This function output a error message.
*
* Pre:	User wrote wrong input in console.
*
* Post:	Errormessage is output in the console.
*
* Parameters:
*
* Returns:	void
*********************************************************************/
void  FullAlphabetTimer::errorMessage()
{
	cout << "Input is not the alphabet with small letters." << endl;
}

int main()
{
	FullAlphabetTimer fullAlphabetTimer;
	fullAlphabetTimer.run();
	return 0;
}