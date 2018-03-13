/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <string>
#include "Exercises3.h"
#include <climits>

Exercises3 exercises;

int main()
{
	long int fatorial = exercises.factorial_rec(5);

	std::cout << "O numero maximo representavel e " << LONG_MAX << std::endl;
	std::cout << fatorial << std::endl;

	return 0;

}