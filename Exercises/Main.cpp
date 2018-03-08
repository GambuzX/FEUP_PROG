/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include "exercises.h"

Exercises exercises;

int main()
{
	int a[5];
	int b[5];
	exercises.readIntArray(a, 5);

	std::cout << exercises.searchMultValuesInIntArray(a, 5, 12, b);
	
	for (int i = 0; i < 5; i++) {
		std::cout << b[i] << std::endl;
	}

	return 0;

}