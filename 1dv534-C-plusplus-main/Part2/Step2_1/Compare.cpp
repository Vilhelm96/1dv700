/**********************************************************************/
// File:	Compare.cpp
// Summary: This class represents is used to compare two c-strings.
// Version:	Version 1.0 - 2020-04-21
// Owner:	Vilhelm Park
// -------------------------------------------
// Log:	2020-04-21	Created the file. 
//		2020-04-22	Completed the method.
//		
/**********************************************************************/

#include "Compare.h"
/*********************************************************************
* Description:	This function compares the c-string that is input in
*				the console with the full alphabet in small letters.
*				If the compared c-strings are not equal return false
*				and if they are equal return true.
*
* Pre:	User has input something in console.
*
* Post:	The input is either good and the application continues or
*		the input needs to be written again.
*
* Parameters:	
*compareInput - The input the user wrote in the console.
*
* Returns:	True if the c-strings are equal and false if they are 
*			not equal.
*********************************************************************/
bool Compare::equal(char * compareInput)
{
	char alphabetSmallLetters[] = "abcdefghijklmnopqrstuvwxyz";
	char *copyInput = compareInput;	//Copy the initial c-string so that it won't be changed at any point.

	//Check if the length is the same, if not return false.
	if (strlen(copyInput) != strlen(alphabetSmallLetters))
	{
		return false;
	}

	for (int i = 0; i < strlen(alphabetSmallLetters); i++)
	{

		//Compare the indexes to each other, if they are not the same return false.
		if (*copyInput++ != alphabetSmallLetters[i])
		{
			return false;
		}

	}

	return true;
}