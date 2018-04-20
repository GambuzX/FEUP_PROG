/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "OOP Classes.h"

using namespace std;

int main()
{
	vector<int> n1 = { 1,2,3,4,12,5,6,75,4 };
	vector<double> n2 = { 12.0, 13.5, 120.120, 113, 56.99 };


	cout << vectorMax(n1) << endl;

	cout << vectorMax(n2) << endl;

	cout << vectorMin(n1) << endl;

	cout << vectorMin(n2) << endl;

	return 0;
}