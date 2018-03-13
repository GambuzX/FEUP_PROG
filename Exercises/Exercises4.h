#pragma once
#include <string>

class Exercises4
{
public:
	//Chapter 4
	bool isHydroxide(char compound[]);
	void testIsHydroxide();
	bool sequenceSearch(std::string s, int nc, char c);
	void decompose(std::string compound);
	void testDecompose();
	std::string normalizeName(std::string name);

	struct Fraction
	{
		int numerator;
		int denominator;
	};

	void readIntArray(int a[], int nElem);
	int searchValueInIntArray(const int a[], int nElem, int value);
	int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]);
};