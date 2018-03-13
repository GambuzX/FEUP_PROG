/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <string>
#include "Exercises4.h"

Exercises4 exercises;

int main()
{
	std::cout << exercises.normalizeName("  abc     EEEDESzbcDOS") << std::endl;

	return 0;

}