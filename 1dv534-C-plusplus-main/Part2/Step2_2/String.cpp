/******************************************************
* File:         String.cpp
* Description:  This is the file with the class String.
*				This class creates a string object,
*				which can add to strings, set a string,
*				compare strings, output and input strings.
*
* Version:      1.0    2020-04-26, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
*2020-04-25		Started working on the class.
*				Vilhelm Park
*2020-04-26		Finished the work.
*				Vilhelm Park
*
******************************************************/

#include "String.h"

//Default String
String::String() = default;

/*********************************************************************
* Description:	This constructor creates a string object and gives it a
*				value.
* Pre: Nothing
* Post:	A string object is created.
* Parameters:
*	string - the string we want for the object.
* Returns:     Nothing
*********************************************************************/
String::String(const String & string)
{
	setString(string.toC_str(), string.getLength());
}

/*********************************************************************
* Description:	This constructor creates a string object and gives it a
*				value.
* Pre:	Nothing
* Post:	A string object is created.
* Parameters:
*	string - the char sequence we want for the object.
* Returns:     Nothing
*********************************************************************/
String::String(const char * string)
{
	setString(string, strlen(string));
}

/*********************************************************************
* Description: This destructor destroys a String object.
* Pre:	We have a String object.
* Post:	String object is deleted.
* Parameters:
* Returns:     Nothing
*********************************************************************/
String::~String()
{
	delete[] _strPtr;
}

/*********************************************************************
* Description: This function adds a string to another string.
* Pre:	We have a string object.
* Post:	We have added a string to another string.
* Parameters:
*	string - string we want to add to the string object.
* Returns:	A full string.
*********************************************************************/
const String String::operator+(const String &string) 
{
	return concatenate(_strPtr, string);
}

/*********************************************************************
* Description: This function adds a string to another string.
* Pre:	We have a string object.
* Post:	We have added a string to another string.
* Parameters:
*	string - char sequence we want to add to the string object.
* Returns:	A full string.
*********************************************************************/
const String String::operator+(const char *string) 
{
	return concatenate(_strPtr, string);
}

/*********************************************************************
* Description: This function sets this string value to a string.
* Pre:	We have a string.
* Post:	We have given a value to a string.
* Parameters:
*	string - the string value we want to give to the string object.
* Returns:     Nothing
*********************************************************************/
void String::operator=(const String &string) 
{
	setString(string.toC_str(), string.getLength());
}

/*********************************************************************
* Description: This function sets this string value to a string.
* Pre:	We have a string.
* Post:	We have given a value to a string.
* Parameters:
*	string - the char sequence value we want to give to the string object.
* Returns:     Nothing
*********************************************************************/
void String::operator=(const char * string) 
{
	setString(string, strlen(string));
}

/*********************************************************************
* Description: This function compares two strings to each other.
* Pre:	We have two strings.
* Post:	Two strings get compared.
* Parameters:
*	string - char sequence we want to compare to a string object.
* Returns:     true or false depending if they are equal or not.
*********************************************************************/
bool String::operator==(const char * string)
{
	if (strcmp(_strPtr, string) != 0)//Compare two strings. Return false if they are not equal.
	{
		return false;
	}

	return true;
}

/*********************************************************************
* Description: This function gets the string pointer.
* Pre:	We have a string.
* Post:	We get the string pointer.
* Parameters:
* Returns:	String value.
*********************************************************************/
const char * String::toC_str() const
{
	return _strPtr;
}

/*********************************************************************
* Description: This function gets the string objects length.
* Pre: We have a string.
* Post:	We get string length. 
* Parameters:
* Returns:	String length.
*********************************************************************/
int String::getLength() const
{
	return _strLen;
}
//Private 

/*********************************************************************
* Description: This function sets a value to the string.
* Pre:	We have a string.
* Post:	We have a value to the string.
* Parameters:
*	str - value we give value to the string.
*	strLength - length to the string.
* Returns:     Nothing
*********************************************************************/
void String::setString(const char * str, int strLength)
{
	this->_strLen = strLength;	
	_strPtr = new char[_strLen + 1];	//Create new pointer 
	memcpy(_strPtr, str, strLength);	//Copy the string in parameter into the string pointer.
	memset(_strPtr + strLength, 0, 1);	//Set null pointer in the end of the string pointer. 
}

/*********************************************************************
* Description: This function concatenates the string to another.
* Pre:	We have a string.
* Post:	We have created a new concatenated string.
* Parameters:
*	cstring - first part of the string.
*	string - second part of the string.
* Returns:	The concanated string.
*********************************************************************/
inline const String String::concatenate(const char *cstring, const String &string) 
{
	int totalStringLength = strlen(cstring) + string.getLength();	//Save the total length of the new string.
	auto *newString = new char [totalStringLength + 1];	//Create a new auto pointer, auto because it can be both String and char*.
	String stringToReturn;	//String that will be returned.

	memcpy(newString, cstring, strlen(cstring));	//Copy first string into newstring.
	memcpy(newString + strlen(cstring), string.toC_str(), string.getLength());	//Copy second string to the newstring, make sure it starts after the first string.
	memset(newString + totalStringLength, 0, 1);	//Set null pointer at the end.
	stringToReturn = newString;	//Copy the string into the string we want to return.
	return stringToReturn;
}
//Friend functions
/*********************************************************************
* Description: This function returns the concatenated string.
* Pre:	We have a string.
* Post:	We concatenate two strings.
* Parameters:
*	cstring - first string.
*	string - second string.
* Returns:	The full string.
*********************************************************************/
const String operator+(const char * cstring, String string)
{
	return string.concatenate(cstring, string);
}

/*********************************************************************
* Description: This function output the string pointer.
* Pre:	We have a string.
* Post:	We output the string pointer.
* Parameters:
*	ostream - lets us output the string pointer.
*	string - string we want to output.
* Returns:	The outputstream.
*********************************************************************/
std::ostream & operator<<(std::ostream &ostream, const String &string)
{
	ostream << string._strPtr;
	return ostream;
}

/*********************************************************************
* Description: This function lets us input the string pointer value.
* Pre: We have a string.
* Post:	We have given a new value to the string pointer.
* Parameters:
*	istream - lets us input the string pointer.
*	string - string we want to get new string pointer.
* Returns:	The inputstream
*********************************************************************/
std::istream & operator>>(std::istream &istream, String &string)
{
	char tempString[50];	//Set tempstrings size.
	istream >> tempString;	//Input string into tempstring.
	const char *newString = tempString;	//Give a cstring the input.
	string.setString(newString, strlen(newString));	//Set the string new value.
	return istream;
}