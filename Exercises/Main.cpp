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
	exercises.readIntArray(a, 5);

	return 0;

}