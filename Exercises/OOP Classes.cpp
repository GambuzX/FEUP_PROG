#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "OOP Classes.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    DATE                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


