#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
	int a = 12;
	int &b = a;

	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "b: " << b << endl;
	cout << "&b: " << &b << endl;

	return 0;
}