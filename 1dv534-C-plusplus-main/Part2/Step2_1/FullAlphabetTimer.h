//
// File:	FullAlphabetTimer.h
// Summary: This class represents a clock, that can be used to
//			read the correct time. The clock gets its time from
//			your computer's system clock, and returns it in the 
//			form of a MyTime-object.
// Version:	Version 1.2 - 2015-03-05 
// Owner:	Christer Lundberg 
// -------------------------------------------
// Log:	2020-04-21	Created the class.
//
/**********************************************************************/
#ifndef FULLALPHABETTIMER_H
#define FULLALPHABETTIMER_H

#include "Compare.h"
#include "Clock.h"
#include "MyTime.h"
#include <iostream>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;


class FullAlphabetTimer
{
public:
	void run();

private:
	MyTime returnCurrentTime();
	void errorMessage();
	Clock* clock;
	Compare* comp;
	char input[100];
	int alphabetLength = 100;
	bool startTimer = false;
};
#endif