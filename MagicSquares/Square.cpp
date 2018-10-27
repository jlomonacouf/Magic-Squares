#include "stdafx.h"
#include "Square.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Square::Square(int dimensions)
{
	this->dimensions = dimensions;
	matrix = new int*[dimensions];
	for (int i = 0; i < dimensions; i++)
		matrix[i] = new int[dimensions];

	generateElements();
}

int Square::getDimensions()
{
	return dimensions;
}

int* Square::getRow(int index)
{
	if (index < dimensions)
		return matrix[index];
}

int* Square::getColumn(int index)
{
	int* column = new int[dimensions];
	for (int i = 0; i < dimensions; i++)
	{
		column[i] = matrix[i][index];
	}
	return column;
}

int Square::addRow(int index)
{
	int* row = getRow(index);
	int sum = 0;

	for (int i = 0; i < dimensions; i++)
		sum += row[i];

	return sum;
}

int Square::addColumn(int index)
{
	int* column = getColumn(index);
	int sum = 0;

	for (int i = 0; i < dimensions; i++)
		sum += column[i];

	return sum;
}

int* Square::addDiagonals()
{
	int* diagonals = new int[2];

	diagonals[0] = 0;
	for (int i = 0; i < dimensions; i++)
	{
		diagonals[0] += matrix[i][i];
	}

	diagonals[1] = 0;
	for (int i = dimensions - 1; i >= 0; i--)
	{
		diagonals[1] += matrix[i][i];
	}

	return diagonals;
}

void Square::generateElements()
{
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			matrix[i][j] = ((i + j + 1 + (dimensions / 2)) % dimensions) + ((i + 2 * j + 1) % dimensions) + 1;
		}
	}
}

void Square::alternateGenerateElements()
{
	int index = 0;
	int j = dimensions / 2;

	for (int k = 1; k <= dimensions * dimensions; ++k)
	{
		matrix[index][j] = k;

		index--;
		j++;

		if (k%dimensions == 0)
		{
			index += 2;
			--j;
		}
		else
		{
			if (j == dimensions)
				j -= dimensions;
			else if (index<0)
				index += dimensions;
		}
	}
}

void Square::printSquare() // Prints out every element of the current matrix array and checks if it is a magic square
{
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			printf("%-5d", matrix[i][j]);
		}
		cout << endl;
	}
	
	if (!checkSquare())
	{
		cout << endl << "Error: Square is not a Magic Square." << endl;
	}

}

void Square::printMagic() // Generates 10 magic squares and prints them out
{
	cout << "Magic Square #1 is" << endl << endl;
	if (dimensions == 3) // Use the alternative algorithm to generate elements if the magic square is 3x3
		alternateGenerateElements();
	printSquare();

	cout << endl << endl << "Magic Square #2 is" << endl << endl;
	reflectMatrixVertical();
	printSquare();

	cout << endl << endl << "Magic Square #3 is" << endl << endl;
	reflectMatrixHorizontal();
	printSquare();

	cout << endl << endl << "Magic Square #4 is" << endl << endl;
	reflectMatrixVertical();
	printSquare();

	cout << endl << endl << "Magic Square #5 is" << endl << endl;
	transposeMatrix();
	printSquare();

	cout << endl << endl << "Magic Square #6 is" << endl << endl;
	reflectMatrixVertical();
	printSquare();

	cout << endl << endl << "Magic Square #7 is" << endl << endl;
	reflectMatrixHorizontal();
	printSquare();

	cout << endl << endl << "Magic Square #8 is" << endl << endl;
	reflectMatrixVertical();
	printSquare();

	cout << endl << endl << "Magic Square #9 is" << endl << endl;
	if (dimensions == 3) // Use the alternative algorithm to generate elements if the magic square is 3x3
		generateElements();
	else
		alternateGenerateElements();
	printSquare();

	cout << endl << endl << "Magic Square #10 is" << endl << endl;
	transposeMatrix();
	printSquare();
}

void Square::reflectMatrixVertical() //Flips Matrix across vertical axis. Used to generate unique magic square
{
	for (int i = 0; i < dimensions / 2; i++)
	{
		int* temp = matrix[dimensions - i - 1];
		matrix[dimensions - i - 1] = matrix[i];
		matrix[i] = temp;
	}
}

void Square::reflectMatrixHorizontal() //Flips Matrix across horizontal axis. Used to generate unique magic square
{
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions / 2; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][dimensions - j - 1];
			matrix[i][dimensions - j - 1] = temp;
		}
	}
}

void Square::transposeMatrix() //Transposes each element in the matrix. Used to generate unique magic square
{
    int** temp = new int*[dimensions];
	for (int i = 0; i < dimensions; i++)
		temp[i] = new int[dimensions];

	for (int i = 0; i < dimensions; i++)
		for (int j = 0; j < dimensions; j++)
			temp[i][j] = matrix[i][j];

	for (int i = 0; i < dimensions; i++)
		for (int j = 0; j < dimensions; j++)
			matrix[i][j] = temp[j][i];
}

bool Square::checkSquare() //Checks if the current matrix is a magic square
{
	int sum;

	cout << endl << "Checking the sums of every row:        ";

	sum = addRow(0);
	for (int i = 0; i < dimensions; i++)
	{

		cout << addRow(i) << "   ";
		if (addRow(i) != sum)
		{
			return false;
		}
	}

	cout << endl << "Checking the sums of every column:     ";

	sum = addColumn(0);
	for (int i = 0; i < dimensions; i++)
	{
		cout << addColumn(i) << "   ";
		if (addColumn(i) != sum)
		{
			return false;
		}
	}

	int* diagonals = addDiagonals();
	cout << endl << "Checking the sums of every diagonal:   " << diagonals[0] << "   " << diagonals[1];

	if (diagonals[0] != diagonals[1])
		return false;

	return true;
}