/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "examStudy.h"

using namespace std;

int main()
{
	bool success = simplifyNamesFile();

	if (!success)
	{
		cerr << "people1.txt not found\n";
		exit(1);
	}

	return 0;
}