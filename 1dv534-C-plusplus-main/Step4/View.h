/******************************************************
* File:         View.h
* Description:  This is the header for the view.
*
* Version:      1.0    2020-08-16, Linnéuniversitetet
* Author:       Vilhelm Park, Linnéuniversitetet
******************************************************
*               Update Log
*               ----------
* 2020-08-16	Finalize comments		Vilhelm Park
*
******************************************************/

#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

class View
{
public:
	View() = default;
	~View() = default;
	void println(string string);
	void print(string string);
	void printError(string error);
	void write(int &integer);
	void write(string &string);

private:

};
#endif
