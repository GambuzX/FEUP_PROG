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
	Date date(1999, 3, 26), date1 (1,1,1), date2 (2019, 4, 25), date3 (1999, 3, 25), date4 (1999,4,26);

	cout << date.isAfter(date3) << " - " << date.isAfter(date4) << " - " << date3.isAfter(date) << " - " << date2.isAfter(date3) << " - " << date1.isAfter(date3) << endl << endl;
	cout << date.isBefore(date3) << " - " << date.isBefore(date4) << " - " << date3.isBefore(date) << " - " << date2.isBefore(date3) << " - " << date1.isBefore(date3) << endl << endl;

	cout << date.isAfter(date) << " - " << date.isBefore(date) << " - " << date.isEqualTo(date) << " - " << date.isNotEqualTo(date) << " - " << date.isEqualTo(date3) << endl << endl;

	return 0;
}