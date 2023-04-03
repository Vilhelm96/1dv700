/******************************************************
* File:         String.h
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
#ifndef STRING_H // String.h 
#define STRING_H 

#include <cstring>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String {
	friend const String operator+(const char* cstring, String string);				//The friend functions.
	friend std::ostream& operator<<(std::ostream &ostream, const String &string);
	friend std::istream& operator>>(std::istream &istream, String &string);

public:     
	String();	//Default constructor.
	String(const String &string);	//Constructor with a string in the parameter.
	String(const char *string);		//Constructor with a cstring in the parameter.
	~String();	//Destructor.
	const String operator+(const String &string);	//The plus operator for string.
	const String operator+(const char* string);		//The plus operator for cstring.
	void operator=(const String& string);			//The sum operator for the string.
	void operator=(const char* string);				//The sum operator for the cstring.
	bool operator==(const char* string);			//The equals operator for cstring.
	const char* toC_str() const;	//Returns the string pointer.
	int getLength() const;			//Returns the string length.
private:       
	char* _strPtr;	//The cstring pointer.
	int _strLen;
	void setString(const char *str, int strLength);	//The function that set a new string pointer.
	inline const String concatenate(const char *cstring ,const String &string);	//The function that concatenate strings into one.
}; 
#endif /* STRING_H */ 