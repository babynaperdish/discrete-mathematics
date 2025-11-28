#include <iostream>
#include <conio.h>
#include "mySet.h"

using namespace std;

int main() {
string symbol;
	while (true)
	{
		cout << "To start the program, enter \"s\". To shut down programm press \"q\"." << endl;
		while (true)
		{
			cin.clear();
			symbol = _getch();
			if (symbol == "q" || symbol == "Q") {
				cout << "Shutting down the program" << endl;
				return 0;
			}
			else if (symbol == "s" || symbol == "S")
			{
				mySet testSet;
				testSet.printOperations();
				break;
			}
			else
			{
				cout << "Incorrect input, try again: " << endl;
				cin.clear();
				symbol = _getch();
			}
		}
		if (symbol == "q" || symbol == "Q") {
			cout << "Shutting down the program" << endl;
			break;
		}
	}
	return 0;
}

