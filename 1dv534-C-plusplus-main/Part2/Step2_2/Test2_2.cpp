
/******************************************************
* File:         Test2_2.cpp
* Description:  This is the file that test that the 
*				class works as intended.
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
#include "Test2_2.h"
#include "String.h"

/*********************************************************************
* Description:	This function runs the functions from the new String
*				and tries so that it works.
*			
* Pre:	Nothing.
* Post:	String is tested.
* Parameters:
* Returns:     Nothing
*********************************************************************/
void Test2_2::run()
{
	String str1("Hello ");
	String str2(str1);
	cout << str1 << str2 << endl; // Shall print "Hello Hello "
	str2 = "my world!";
	cout << str1 << str2 << endl; // Shall print "Hello my world!"
	String str3;
	cout << "Enter a name: ";
	cin >> str3;   // (...User enters for instance "Pluto"...)

	str2 = str1 + str3;

	cout << str2 <<  endl;  // Shall print "Hello Pluto"
	str2 = "Goodbye " + str3;
	cout << str2  << endl;  // Shall print "Goodbye Pluto"
	cout << str1 <<"and " << "Goodbye " << (str1 == "Goodbye " ? "is " : "is not ") << "the same word!\n";   // Shall print "Hello and Goodbye is not the same word!"
}

//Implements the Test2_2 class and runs the function.
int main() {
	Test2_2 test2;
	test2.run();
	cin.get();
	return 0;
} 