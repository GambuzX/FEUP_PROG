/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "OOP Classes.h"

using namespace std;

int main()
{
	Student student;

	student = readStudentData();

	cout << student.getName() << " - " << student.getCode() << " - " << student.getFinalGrade() << endl;

	return 0;
}