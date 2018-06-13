#include "examStudy.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void simplify(const string & name, string & sName)
{
	istringstream istream(name);
	vector<string> names;
	string placeholder;

	while (istream >> placeholder)
	{
		names.push_back(placeholder);
	}

	if (names.size() == 1)
		sName = names.at(0);
	else
		sName = names.at(0) + " " + names.at(names.size() - 1);
	return;	
}

bool simplifyNamesFile()
{
	ifstream inputfile("people1.txt");
	if (!inputfile.is_open())
		return false;

	ofstream outputFile("people2.txt");

	string line = "";
	while (getline(inputfile, line))
	{
		string placeholder;
		simplify(line, placeholder);
		outputFile << placeholder << endl;
	}

	inputfile.close();
	outputFile.close();
	return true;
}

Date::Date(int y, int m, int d )
{
	this->y = y;
	this->m = m;
	this->d = d;
}

bool operator<(const Date& left, const Date& right)
{
	string leftDate, rightDate;
	ostringstream ostream;

	ostream << left.y << left.m << left.d;
	leftDate = ostream.str();

	ostream.str("");
	ostream << right.y << right.m << right.d;
	rightDate = ostream.str();

	return leftDate < rightDate;
}

bool operator==(const Date & left, const Date & right)
{
	return false;
}

istream& operator>> (istream& f, Date& date)
{
	string line;
	getline(f, line);
	istringstream istream(line);

	char hifen;
	int year, month, day;
	istream >> year >> hifen >> month >> hifen >> day;
	
	if (f.fail() || year < 0 || month < 0 || day < 0)
		throw runtime_error("invalid Date");

	date.d = day;
	date.m = month;
	date.y = year;
	return f;
}
