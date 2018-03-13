/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <string>
#include "Exercises3.h"
#include <climits>

Exercises3 exercises;
double h(double);

int main()
{
	//integrateTR(double f(double), double a, double b, int n)

	std::cout << exercises.integrateTR(h, -2, 2, 2) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 4) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 8) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 16) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 32) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 64) << std::endl;
	std::cout << exercises.integrateTR(h, -2, 2, 128) << std::endl;

	return 0;

}

double h(double x)
{
	return sqrt(4 - x * x);
}