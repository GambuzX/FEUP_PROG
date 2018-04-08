/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Exercises1.h"
#include "Exercises2.h"
#include "Exercises3.h"
#include "Exercises4.h"

using namespace std;

int main()
{
	double result = executeOperation("49/12");

	cout << fixed << setprecision(2) << result << endl;

	return 0;
}