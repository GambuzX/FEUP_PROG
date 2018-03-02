#include <iostream>
#include <string>

using namespace std;

void desafioPeekNumber()
{
	int number;
	bool validNumber = false;

	cout << "Introduce a number between letters and/or symbols: ";
	
	do
	{
		cin >> number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (cin)
		{
			validNumber = true;
		}
	} while (!validNumber);

	cout << "The hidden number was: " << number << endl;	
}