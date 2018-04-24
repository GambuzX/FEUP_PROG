#ifndef OOPCLASSES_H
#define OOPCLASSES_H

#include <fstream>
#include <string>
#include <vector>
#include <iterator>

///////////////////////////////////////////////////////////////////////////////////////////
//                                     CLASSES                                           //
///////////////////////////////////////////////////////////////////////////////////////////
class Date
{
public:
	Date(); // default constructor based on current date
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(std::string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();
	std::string getDate(); // returns the date in format "yyyy/mm/dd"
	void show(); // shows the date on the screen in format "yyyy/mm/dd"
	bool isValid(); //returns a boolean value indicating whether the date is valid or not
	bool isEqualTo(Date &date) const;
	bool isNotEqualTo(Date &date) const;
	bool isAfter(Date &date) const;
	bool isBefore(Date &date) const;

private:
	unsigned int year;
	unsigned int month;
	unsigned int day;

	bool isLeapYear(int year);
	int daysInMonthOfYear(int month, int year);	
};


class Student
{
public: 
		Student(); 
		Student(const std::string &code, const std::string &name); 
		void setGrades(double shortExam, double project, double exam); 
		std::string getCode() const;
		std::string getName() const;
		int getFinalGrade() const; 
		// other get and set methods 
		bool isApproved() const; // is the student approved or not ?
		static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private: 
		std::string code; // student code 
		std::string name; // student complete name 
		double shortExam, project, exam; // grades obtained by the student in the different components 
		int finalGrade; 
};

class Person
{
public:
	std::string getName();
	std::string getGender();
	Date getBirthdate();
private:
	std::string name;
	std::string gender;
	Date birthdate;
};

///////////////////////////////////////////////////////////////////////////////////////////
//                                     FUNCTIONS                                         //
///////////////////////////////////////////////////////////////////////////////////////////


Student readStudentData();
void showAboveAverageStudents(std::ostream &outputStream, std::vector<Student> students);
void readStudentsAndShowAboveAverage(std::vector<Student> &);
void readAndStoreStudentsTextFile();

template <typename T>
T vectorMax(std::vector<T> numbers)
{
	T max = numbers.at(0);
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.at(i) > max)
			max = numbers.at(i);
	}
	return max;
}

template <typename T>
T vectorMin(std::vector<T> numbers)
{
	T min = numbers.at(0);
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.at(i) < min)
			min = numbers.at(i);
	}
	return min;
}

#endif
