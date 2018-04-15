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


