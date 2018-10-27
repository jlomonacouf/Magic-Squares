#pragma once
class Square
{
public:
	Square(int dimensions);
	int getDimensions();
	int addRow(int index);
	int addColumn(int index);
	int* addDiagonals();
	void printSquare();
	void printMagic();

private:
	int dimensions;
	int** matrix = 0;

	void generateElements();
	void alternateGenerateElements();
	int* getRow(int index);
	int* getColumn(int index);
	bool checkSquare();

	void reflectMatrixVertical();
	void reflectMatrixHorizontal();
	void transposeMatrix();

};

