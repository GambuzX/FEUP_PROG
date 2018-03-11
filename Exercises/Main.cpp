/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <string>
#include "exercises.h"

Exercises exercises;

int main()
{
	std::cout << exercises.normalizeName("  abc     EEEDESzbcDOS") << std::endl;

	return 0;

}