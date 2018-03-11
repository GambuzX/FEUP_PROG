/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include "exercises.h"

Exercises exercises;

int main()
{
	std::cout << exercises.sequenceSearch("abzzzzzzzzzzzzcvdz", 12, 'z') << std::endl;

	return 0;

}