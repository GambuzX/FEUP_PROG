#pragma once

class Exercises
{
public:
	void intro_exe();
	void exe1_1();
	void exe1_2();
	void exe1_3();
	void exe1_4();
	void exe1_5();
	float exe1_6();
	void exe2_2_a();
	void exe2_2_b();
	void exe2_2_c();
	void exe2_3();
	void exe2_4();
	void exe2_5();
	void exe2_6_a();
	bool isPrime(int number);
	void exe2_6_b();
	void exe2_6_c();
	void exe2_7_a();
	void exe2_7_b();
	void exe2_9_a();
	void exe2_9_b();
	void exe2_9_c();
	void exe2_10_a();
	void exe2_10_b();
	double exe2_11_a();
	double exe2_11_b();
	double exe2_11_c();
	void exe2_13();
	void exe2_14_a();
	void exe2_14_b();
	int exe3_8(int m, int n);
	double distance(double x1, double y1, double x2, double y2);
	double area(double x1, double y1, double x2, double y2, double x3, double y3);
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

private:


};