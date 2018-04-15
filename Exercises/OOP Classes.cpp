#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "OOP Classes.h"

using namespace std;

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


