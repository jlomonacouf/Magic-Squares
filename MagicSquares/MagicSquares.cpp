// MagicSquares.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Square.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int size;
	cout << "Enter the size of a magic square: ";
	cin >> size;
	while (cin.fail() || !((size >= 3 && size <= 15) && (size % 2 == 1))) //Checks if the input is an odd number between 3 and 15
	{
		cout << "Please only enter odd whole numbers between 3 and 15" << endl;
		cin.clear();
		cin.ignore(256, '\n');

		cout << "Enter the size of a magic square: ";
		cin >> size;
	}
	cout << endl;

	Square magic(size);

	magic.printMagic(); //Generates and prints out 10 different magic squares

	int x;
	cin >> x; //Waits for user input to close program

    return 0;
}

