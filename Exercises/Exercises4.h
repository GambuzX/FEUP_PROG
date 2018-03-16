#pragma once
#include <string>
#include <vector>

//Chapter 4

struct Fraction
{
	int numerator;
	int denominator;
};

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

void readIntVector(std::vector<int> &v, int nElem);
int searchValueInVector(const std::vector<int> &v, int value);
std::vector<int> searchMultValuesInIntVector(const std::vector<int> &v, int value);
std::vector<int> readIntVector();

void bubblesort(std::vector<std::string> &v);