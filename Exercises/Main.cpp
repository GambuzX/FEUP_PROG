/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "OOP Classes.h"

using namespace std;

int main()
{
	Date date(1999, 3, 26);
	date.show();
	cout << date.isValid() << endl;

	date.setYear(2017);
	date.setMonth(2);
	date.setDay(29);
	date.show();
	cout << date.isValid() << endl;

	return 0;
}