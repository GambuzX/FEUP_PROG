/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <string>
#include <vector>
#include "Exercises1.h"
#include "Exercises2.h"
#include "Exercises3.h"
#include "Exercises4.h"

using namespace std;

int main()
{
	vector<int> numbers = { 1,2,2,2,2,2,2,3,4,5,6,6,7,12342,3423,23,43,12,12,12,12,12 };

	RemoveDuplicates(numbers);

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers.at(i) << " ";
	}

	return 0;
}