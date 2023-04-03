/******************************************************
* File:         TextHandler.h
* Description:  This is the header for TextHandler.
*
* Version:      1.0    2020-05-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
*
******************************************************/
#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <fstream>
#include <cstring>
#include <iostream>
#include <cfloat> 
#include <cerrno>

using std::cout;
using std::endl;
using std::cin;

class TextHandler 
{
public:
	TextHandler(const char* textFile, int maxSize);		//Constructor
	~TextHandler();		//Destructor
	int nrOfTexts();	
	int maxNrOfTexts();
	const char* text(int option);

private:
	void loadStories(const char* fileName);
	char **allStories;	//Vector for the stories.
	int theMaxSize;	//Max amount of stories in vector.
	int currentAmountOfTexts = 0;	//Current amount of texts in the vector.
	int currentLength = 0;	//Total length of all the stories in the vector.
};
#endif