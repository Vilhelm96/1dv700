/**********************************************************************
* File:         TextHandler.cpp
* Description:  This is a class that loads a text file of stories into
*				a vector. It can return whatever story the user wants.
*
* Version:      1.0    2020-05-17, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
***********************************************************************
*               Update Log
*               ----------
* 2020-05-16	Starting to figure out what to do.		Vilhelm Park
* 2020-05-17	Ran into several severe issues.
* 2020-05-18	Fixed the issues.
*
**********************************************************************/

#include "TextHandler.h"

/*********************************************************************
* Description: This is the constructor.
* Pre:
* Post:	Creates a TextHandler object.
* Parameters:
*	textFile - the file containing the stories.
*	maxSize - the maximum number of text.
* Returns:     Nothing
*********************************************************************/
TextHandler::TextHandler(const char* textFile, int maxSize)
{
	theMaxSize = maxSize;
	allStories = new char *[theMaxSize];
	loadStories(textFile);
}

/*********************************************************************
* Description: This is the destructor.
* Pre:
* Post:	Vector containing the stories is deleted.
* Parameters:
* Returns:     Nothing
*********************************************************************/
TextHandler::~TextHandler()
{
	for (int counter = 0; counter < currentAmountOfTexts; counter++)
	{
		delete[] allStories[counter];	//Deletes all stories in vector.
	}
	delete[] allStories;	//Delete vector.
}

/*********************************************************************
* Description: This function returns the current amount of stories in
*				vector.
* Pre:
* Post:	Return current amount of stories in vector.
* Parameters:
* Returns:     current amount of stories in vector.
*********************************************************************/
int TextHandler::nrOfTexts()
{
	return currentAmountOfTexts;
}

/*********************************************************************
* Description: This function returns the maximum amount of stories in
*				vector.
* Pre:
* Post:	Returns maximum amount of stories in vector.
* Parameters:
* Returns:	Maximum amount of stories in vector.
*********************************************************************/
int TextHandler::maxNrOfTexts()
{
	return theMaxSize;
}

/*********************************************************************
* Description: This function return the story in the index.
* Pre:
* Post:	Return a story from vector.
* Parameters:
*	option - index in vector
* Returns:     A story from vector.
*********************************************************************/
const char* TextHandler::text(int option)
{
	//If index over 5 return null.
	if (option >= currentAmountOfTexts)
	{
		return nullptr;
	}

	char* aStory = allStories[option];
	return aStory;
}

/*********************************************************************
* Description: This function loads the stories into the vector.
* Pre:	Vector is empty.
* Post:	Vector is full.
* Parameters:
*	textFile - the file that cotains the stories.
* Returns:     Nothing
*********************************************************************/
void TextHandler::loadStories(const char* textFile)
{
	std::ifstream storiesFile(textFile, std::ios::in);
	const char *paragraphEnder = "%%%%%";
	const int maxSize = 10000;
	char oneLine[maxSize];
	char fullStory[maxSize];
	int lineLength = 0;
	int currentStringLength = 0;
	int counter = 0;

	//Check if file is open and is good.
	if (!storiesFile.is_open() && !storiesFile.good())
	{
		cout << "Not correct file name try again!";
		return;
	}

	storiesFile.getline(oneLine, maxSize);

	//Run until end of file
	while (!storiesFile.eof())
	{
		storiesFile.getline(oneLine, maxSize);

		// Put current story in vector and reset string.
		if (memcmp(oneLine, paragraphEnder, 5) == 0)
		{
			//set null pointer in the end of the cstring.
			memset(fullStory + strlen(fullStory), 0, 1);
			currentLength += currentStringLength;
			char *storyString = nullptr;

			//Try creating a new cstring
			try
			{
				storyString = new char[currentStringLength + 1];
			}
			//Catch any exception 
			catch (...)
			{
				//Delete the vector and then throw exception.
				this->~TextHandler();
				throw;
			}

			//If the characters in all stories is 10 000 or more something is wrong.
			if (currentLength >= maxSize)
			{
				this->~TextHandler();	//Delete vector and it's contents. Then throw runtime error since, this error won't
										//get noticed else.
				throw std::runtime_error("The stories have exceeded the max length of 10 000 characters, something is wrong try again!\n");
				return;
			}

			//Copy cstring into dynamic cstring.
			memcpy(storyString, fullStory, currentStringLength);
			//Set nullpointer in dynamic cstring
			storyString[currentStringLength] = '\n';	//Add new line at the end
														//since it gets removed when we copy the fullstory string.
														//By doing this we get the correct amount of characters. Then of course add null pointer after.
			storyString[currentStringLength + 1] = '\0';

			//Add story to vector
			allStories[currentAmountOfTexts++] = storyString;	//Put a story in the vector.
			memset(fullStory, 0, sizeof(fullStory));	//Reset cstring.
			counter = 0;
			currentStringLength = 0;
		}

		//Else load another line into the cstring
		else
		{
			//Only first iteration for each story
			if (counter == 0)
			{
				lineLength = strlen(oneLine);
				currentStringLength += lineLength;
				//Fill the first row in the story into the cstring and
				//set a new row and then a null pointer at the end.
				memcpy(fullStory, oneLine, lineLength);
				memset(fullStory + lineLength, 10, 1);
				memset(fullStory + lineLength + 1, 0, 1);
				//Add to the current string counter.
				counter++;
			}

			else
			{
				lineLength = strlen(oneLine);
				currentStringLength += lineLength;
				//Concatenate the new row into the cstring.
				strcat_s(fullStory, maxSize, oneLine);
				//Set a new row at the end of the cstring and then after that a null pointer.
				memset(fullStory + currentStringLength + 1, 10, 1);
				memset(fullStory + currentStringLength + 2, 0, 1);
				currentStringLength++;
			}

		}
	}
	//Close file
	storiesFile.close();
}