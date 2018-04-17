#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>
#include "OOP Classes.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    DATE                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Date::Date()
{
	auto currentT = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(currentT);
	string time = ctime(&currentTime); // Format: Www Mmm dd hh:mm:ss yyyys

	istringstream iss(time);
	string thrash, monthString;

	iss >> thrash >> monthString >> day >> thrash >> year;

	if (monthString == "Jan") month = 1;
	else if (monthString == "Feb") month = 2;
	else if (monthString == "Mar") month = 3;
	else if (monthString == "Apr") month = 4;
	else if (monthString == "May") month = 5;
	else if (monthString == "Jun") month = 6;
	else if (monthString == "Jul") month = 7;
	else if (monthString == "Aug") month = 8;
	else if (monthString == "Sep") month = 9;
	else if (monthString == "Oct") month = 10;
	else if (monthString == "Nov") month = 11;
	else month = 12;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(std::string yearMonthDay)
{
	istringstream istr(yearMonthDay);
	char bar;
	istr >> year >> bar >> month >> bar >> day;
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

unsigned int Date::getYear()
{
	return year;
}

unsigned int Date::getMonth()
{
	return month;
}

unsigned int Date::getDay()
{
	return day;
}

std::string Date::getDate()
{
	ostringstream outs;
	outs << year << '/' << month << '/' << day;
	return outs.str();
}

void Date::show()
{
	cout << getDate() << endl;
}

bool Date::isValid()
{
	if (year <= 0) return false;
	if (month <= 0 || month > 12) return false;
	return (day > 0 && day <= daysInMonthOfYear(month, year));
}

bool Date::isEqualTo(Date & date) const
{
	if (day != date.getDay()) return false;
	if (month != date.getMonth()) return false;
	if (year != date.getYear()) return false;
	return true;
}

bool Date::isNotEqualTo(Date & date) const
{
	if (day != date.getDay()) return true;
	if (month != date.getMonth()) return true;
	if (year != date.getYear()) return true;
	return false;
}

bool Date::isAfter(Date & date) const
{
	if (year > date.getYear()) return true;
	if (year < date.getYear()) return false;

	//same year
	if (month > date.getMonth()) return true;
	if (month < date.getMonth()) return false;

	//same year and same month
	if (day > date.getDay()) return true;
	else return false;
}

bool Date::isBefore(Date & date) const
{
	if (year > date.getYear()) return false;
	if (year < date.getYear()) return true;

	//same year
	if (month > date.getMonth()) return false;
	if (month < date.getMonth()) return true;

	//same year and same month
	if (day >= date.getDay()) return false;
	else return true;
}

bool Date::isLeapYear(int year)
{
	// Returns a boolean representing whether or not the year is a Leap Year
	bool bLeapYear;

	if (year % 400 == 0) //divisivel por 400
		bLeapYear = true;
	else if (year % 100 != 0 && year % 4 == 0) //divisivel por 4, mas não por 100
		bLeapYear = true;
	else
		bLeapYear = false;

	return bLeapYear;
}

int Date::daysInMonthOfYear(int month, int year)
{
	//returns the number of days of the specified month in the specified year
	bool leapYear = isLeapYear(year);

	switch (month)
	{
	case 1:	return 31;
	case 2:	if (leapYear)
		return 29;
			else
				return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;

	default:
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    STUDENT                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

Student::Student()
{
}

Student::Student(const string & code, const string & name)
{
	this->code = code;
	this->name = name;
}

void Student::setGrades(double shortExam, double project, double exam)
{
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;

	double finalExamGrade = (double) shortExam * weightShortExam / 100 + project * weightProject / 100 + exam * weightExam / 100;
	double decimal = finalExamGrade - (int)finalExamGrade;
	if (decimal >= 0.5)
		finalGrade = round(finalExamGrade + 0.1);
	else
		finalGrade = round(finalExamGrade);
}

std::string Student::getCode() const
{
	return code;
}

std::string Student::getName() const
{
	return name;
}

int Student::getFinalGrade() const
{
	return finalGrade;
}

bool Student::isApproved() const
{
	return finalGrade >= 8.5f;
}

Student Student::readStudentData()
{
	Student localStudent;

	string stringInput;
	double shortExamG, projectG, examG;
	cout << "Student code? "; 
	cin >> stringInput;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Student code? "; 
		cin >> stringInput;
	}
	localStudent.code = stringInput;

	cin.ignore(10000, '\n'); //ignore line
	cout << "Student Name? "; 
	getline(cin, stringInput);
	localStudent.name = stringInput;

	cout << "Short exame grade? ";
	cin >> shortExamG;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Short exame grade? "; 
		cin >> shortExamG;
	}

	cout << "Project grade? ";
	cin >> projectG;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Project grade? ";
		cin >> projectG;
	}

	cout << "Exam grade? ";
	cin >> examG;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Exam grade? ";
		cin >> examG;
	}
	localStudent.setGrades(shortExamG, projectG, examG);
	return localStudent;
}
