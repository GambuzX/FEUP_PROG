#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
	const char ENTER = 13;
	char ch;
	cout << "chars (end with Z) ? \n";
	do {
		ch = _getch(); //note: returns 13 (CARRIAGE RETURN) when ENTER key is typed
					   // TRY: cin.get()
		cout << ch << "-" << unsigned(ch) << endl;
	} while (ch != 'Z');
	return 0;
}