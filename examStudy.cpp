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

	string line;
	while (getline(cin, line))
	{
		string placeholder;
		simplify(line, placeholder);
		outputFile << placeholder << endl;
	}

	inputfile.close();
	outputFile.close();
	return true;
}
