#pragma once

class Exercises3
{

public:
	//Chapter 3
	int exe3_8(int m, int n);
	double distance(double x1, double y1, double x2, double y2);
	double area(double x1, double y1, double x2, double y2, double x3, double y3);
	double round(double x, unsigned n);
	void testRound();
	bool readFracc(int &numerator, int &denominator);
	void writeFracc(int numerator, int denominator);
	int gcd(int a, int b);
	void reduceFracc(int &numerator, int &denominator);
	double addFracc(int &numerator1, int& denominator1, int numerator2, int denominator2);
	double subFracc(int &numerator1, int& denominator1, int numerator2, int denominator2);
	double multFracc(int &numerator1, int& denominator1, int numerator2, int denominator2);
	double divFracc(int &numerator1, int& denominator1, int numerator2, int denominator2);
	bool testFraccOps(int numerator1, int denominator1, int numerator2, int denominator2);
	bool isLeapYear(int year);
	int daysInMonthOfYear(int month, int year);
	int weekDay(int day, int month, int year);
	void writeWeekDay(int day, int month, int year);
	void writeMonth(int month);
	void writeTimetableMonthInYear(int month, int year);
	void writeTimetableYear(int year);
	int recursiveEuclidesAlgorithm(int m, int n);
	bool testEuclidesAlgorithm(int m, int n);
};