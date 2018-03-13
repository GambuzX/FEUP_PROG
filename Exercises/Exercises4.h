#pragma once
#include <string>

struct Fraction
{
	int numerator;
	int denominator;
};

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
	Fraction readFracc();
	Fraction reduceFracc(Fraction f);
	Fraction addFracc(Fraction, Fraction);
	Fraction subFracc(Fraction, Fraction);
	Fraction multFracc(Fraction, Fraction);
	Fraction divFracc(Fraction, Fraction);

	void readIntArray(int a[], int nElem);
	int searchValueInIntArray(const int a[], int nElem, int value);
	int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]);

};