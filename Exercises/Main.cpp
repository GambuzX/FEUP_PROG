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

Exercises4 exercises;

int main()
{
	std::vector<int> vetor(5);
	exercises.readIntVector(vetor, 5);

	std::vector<int> indexes = exercises.searchMultValuesInIntVector(vetor, 12);

	for (int i = 0; i < indexes.size(); i++)
		std::cout << indexes.at(i) << std::endl;

}