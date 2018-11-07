#include "stdafx.h"
#include "minvector.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите послдовательность чисел " << endl;
	cout << "¬водимые числа: ";
	vector <double> vectorNum;
	double doubleNum, min;
	char character[255];
	int i = 0;

	do
	{
		cin >> character;
		doubleNum = atof(character);
		vectorNum.push_back(doubleNum);
	} while (cin.peek() != '\n');

	min = MinInVector(vectorNum);

	for (i = 0; i < vectorNum.size(); ++i)
	{
		vectorNum[i] *= min;
	}

	PrintVector(vectorNum, min);

	return 0;
}
