#ifndef EXAM_STUDY_H
#define EXAM_STUDY_H

#include <iostream>
#include <fstream>
#include <string>

//2016 / 2017 - Normal
void simplify(const std::string &name, std::string& sName);
bool simplifyNamesFile();

class Date
{
	friend std::istream& operator>> (std::istream& f, Date& date);
	friend std::ostream& operator<< (std::ostream& f, const Date & date);
	friend bool operator<(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);

public:
	Date(int y = 1, int m = 1, int d = 1);

private:
	int y, m, d;
};



















#endif