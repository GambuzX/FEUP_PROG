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
	Fraction frac = { 2,3 };
	Fraction frac2 = { 4,5 };
	Fraction newFrac = exercises.multFracc(frac, frac2);
	std::cout << newFrac.numerator << " / " << newFrac.denominator;

	return 0;

}