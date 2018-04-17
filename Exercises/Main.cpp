/* This main function is used to call the exercises included
	in the header file. 
	For reference see 'exercises.h'.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "OOP Classes.h"

using namespace std;

int main()
{
	Student student1("John", "up20154865");
	Student student2("Sophie", "up201548965");
	Student student3("Kate", "up2016846165");
	Student student4("Kevin", "up2017849641");

	student1.setGrades(10, 4, 16);
	student2.setGrades(20, 20, 20);
	student3.setGrades(14, 14, 15);
	student4.setGrades(1, 0, 2);

	vector<Student> students = { student1, student2, student3, student4 };

	showAboveAverageStudents(cout, students);


	return 0;
}