/******************************************************
* File:         View.cpp
* Description:  This is the file that handles the outputs
*				and inputs.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize the comments	Vilhelm Park
*
******************************************************/

#include "View.h"

void View::println(string string)
{
	cout << string << endl;
}

void View::print(string string)
{
	cout << string;
}

void View::printError(string error)
{
	cerr << error << endl;
}

void View::write(int &integer)
{
	char charInteger; 

	do
	{
		cin >> charInteger;

	} while ((int) charInteger < 48 || (int) charInteger > 57);

	integer = (int)charInteger;
}

void View::write(string &string)
{
	cin >> string;
}
